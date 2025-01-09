import time
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.common.by import By
import pandas as pd
import re

# List of websites to scrape
with open('dataset.txt', 'r') as file:
    websites = [line.strip() for line in file.readlines()]

# Data storage
data = []

# Initialize WebDriver
options = webdriver.ChromeOptions()
options.add_argument("--disable-gpu")
options.add_argument("--no-sandbox")
options.add_argument("--headless")
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)

# Set the page load timeout
driver.set_page_load_timeout(180)  # Set timeout to 180 seconds (3 minutes)

# Function to clean non-numeric values
def clean_value(value):
    cleaned_value = re.sub(r'[^\d.]', '', value)
    return float(cleaned_value) if cleaned_value else 0

# Function to calculate contrast ratio between two colors
def get_contrast_ratio(bg_color, text_color):
    def luminance(color):
        rgb = [int(c) for c in color[4:-1].split(",")]
        rgb = [x / 255 for x in rgb]
        rgb = [x / 12.92 if x <= 0.03928 else ((x + 0.055) / 1.055) ** 2.4 for x in rgb]
        return 0.2126 * rgb[0] + 0.7152 * rgb[1] + 0.0722 * rgb[2]
    
    lum1 = luminance(bg_color)
    lum2 = luminance(text_color)
    return (lum1 + 0.05) / (lum2 + 0.05) if lum1 > lum2 else (lum2 + 0.05) / (lum1 + 0.05)

def fetch_website_data(site, retries=3, wait_time=5):
    """Fetch the website data with retry logic"""
    for attempt in range(retries):
        try:
            driver.get(site)
            return driver.page_source  # Return page source or other relevant data
        except TimeoutException as e:
            print(f"Timeout occurred for {site}. Retrying... (Attempt {attempt + 1})")
            time.sleep(wait_time)
        except Exception as e:
            print(f"An error occurred with {site}: {e}")
            break
    print(f"Failed to load {site} after {retries} attempts.")
    return None  # Return None if the site fails to load after retries

# Loop through websites to collect metrics
for site in websites:
    print(f"Processing {site}...")
    website_data = fetch_website_data(site)  # Fetch website data
    if website_data:
        try:
            # Initialize all metrics as None (to match your requirements)
            font_size = None
            line_height = None
            font_family = None
            background_color = None
            text_color = None
            contrast_ratio = None
            content_width = None
            content_height = None
            scroll_depth = None
            grid_layout = None
            total_padding = None
            error = None

            # Collect typography metrics
            font_size = driver.execute_script("return window.getComputedStyle(document.body).fontSize;") or None
            line_height = driver.execute_script("return window.getComputedStyle(document.body).lineHeight;") or None
            font_family = driver.execute_script("return window.getComputedStyle(document.body).fontFamily;") or None

            # Collect color metrics (example: background color)
            background_color = driver.execute_script("return window.getComputedStyle(document.body).backgroundColor;") or None
            text_color = driver.execute_script("return window.getComputedStyle(document.body).color;") or None

            # Collect layout metrics (example: grid column count, whitespace percentage)
            content_width = driver.execute_script("return document.body.clientWidth;") or None
            content_height = driver.execute_script("return document.body.clientHeight;") or None

            # Collect scroll depth
            scroll_position = driver.execute_script("return window.scrollY;") or 0
            total_scroll_height = driver.execute_script("return document.body.scrollHeight;") or 1
            scroll_depth = (scroll_position / total_scroll_height) * 100  # Calculate scroll depth as a percentage

            # Collect grid layout status
            grid_layout = driver.execute_script("""
                const body = document.body;
                const style = window.getComputedStyle(body);
                return style.display === 'grid' || style.display === 'inline-grid';
            """) or None

            # Append the collected data to the list
            data.append({
                "Website": site,
                "Font Size": font_size,
                "Line Height": line_height,
                "Font Family": font_family,
                "Background Color": background_color,
                "Text Color": text_color,
                "Contrast Ratio": contrast_ratio,
                "Content Width": content_width,
                "Content Height": content_height,
                "Scroll Depth (%)": scroll_depth,
                "Grid Layout": grid_layout,
                "Total Padding": total_padding,
                "Error": error
            })
        except Exception as e:
            # Log the error and append None values for all metrics
            print(f"Error collecting data for {site}: {e}")
            data.append({
                "Website": site,
                "Font Size": None,
                "Line Height": None,
                "Font Family": None,
                "Background Color": None,
                "Text Color": None,
                "Contrast Ratio": None,
                "Content Width": None,
                "Content Height": None,
                "Scroll Depth (%)": None,
                "Grid Layout": None,
                "Total Padding": None,
                "Error": str(e)  # Store the error message here
            })
    else:
        # If the website data couldn't be fetched after retries, append None for all values
        data.append({
            "Website": site,
            "Font Size": None,
            "Line Height": None,
            "Font Family": None,
            "Background Color": None,
            "Text Color": None,
            "Contrast Ratio": None,
            "Content Width": None,
            "Content Height": None,
            "Scroll Depth (%)": None,
            "Grid Layout": None,
            "Total Padding": None,
            "Error": "Failed to load site after retries"
        })

# Create a DataFrame from the collected data
df = pd.DataFrame(data)

# Save the dataset to CSV
df.to_csv("web_design_metrics.csv", index=False)

# Close the browser session
driver.quit()

print("Data collection completed.")