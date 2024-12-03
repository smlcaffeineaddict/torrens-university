from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import pandas as pd
import re
import time

# List of websites to scrape
websites = [
    "https://monogrid.com", "https://www.media.monks.com", "https://activetheory.net",
    "https://heydays.no", "https://joancreative.com", "https://www.mirimarus.com",
]

# Data storage
data = []

# Function to clean non-numeric values (remove unwanted characters like 'px', 'auto', and parentheses)
def clean_value(value):
    cleaned_value = re.sub(r'[^\d.]', '', value)  # Remove all non-numeric characters except dot
    return float(cleaned_value) if cleaned_value else 0  # Return 0 if cleaned_value is empty

# Function to calculate the contrast ratio between two colors (background and text)
def get_contrast_ratio(color1, color2):
    def luminance(color):
        rgb = [int(c) for c in color[4:-1].split(",")]
        rgb = [x / 255 for x in rgb]
        rgb = [x / 12.92 if x <= 0.03928 else ((x + 0.055) / 1.055) ** 2.4 for x in rgb]
        return 0.2126 * rgb[0] + 0.7152 * rgb[1] + 0.0722 * rgb[2]

    # Calculate luminance of both colors
    lum1 = luminance(color1)
    lum2 = luminance(color2)
    
    # Calculate contrast ratio (WCAG 2.0 standard)
    if lum1 > lum2:
        return (lum1 + 0.05) / (lum2 + 0.05)
    else:
        return (lum2 + 0.05) / (lum1 + 0.05)

# Function to safely get elements with retry for stale element reference
def get_element_safe(driver, xpath, retries=3):
    for attempt in range(retries):
        try:
            element = WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.XPATH, xpath))
            )
            return element
        except Exception as e:
            print(f"Attempt {attempt + 1}: Error - {e}")
            if attempt < retries - 1:
                time.sleep(1)  # Retry after a small delay
            else:
                print("Max retries reached for this element.")
                return None

# Initialize the Chrome WebDriver with WebDriver Manager
options = webdriver.ChromeOptions()
options.add_argument("user-data-dir=/tmp/chrome_user_data")
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)

# Loop through websites to collect metrics
for site in websites:
    driver.get(site)
    time.sleep(2)  # Let the page load

    try:
        # Collect typography metrics
        font_size = driver.execute_script("return window.getComputedStyle(document.body).fontSize;") or 'NULL'
        line_height = driver.execute_script("return window.getComputedStyle(document.body).lineHeight;") or 'NULL'
        font_family = driver.execute_script("return window.getComputedStyle(document.body).fontFamily;") or 'NULL'
        
        # Collect color metrics (example: background color and text color)
        background_color = driver.execute_script("return window.getComputedStyle(document.body).backgroundColor;") or 'NULL'
        text_color = driver.execute_script("return window.getComputedStyle(document.body).color;") or 'NULL'
        
        # Contrast ratio between background and text color
        contrast_ratio = get_contrast_ratio(background_color, text_color) if background_color != 'NULL' and text_color != 'NULL' else 0
        
        # Collect layout metrics (example: grid usage and whitespace distribution)
        content_width = driver.execute_script("return document.body.clientWidth;") or 1  # Default to 1 to avoid division by zero
        content_height = driver.execute_script("return document.body.clientHeight;") or 1  # Default to 1 to avoid division by zero
        
        # Check if the website uses CSS grid layout
        grid_layout = driver.execute_script("""
            const body = document.body;
            const style = window.getComputedStyle(body);
            return style.display === 'grid' || style.display === 'inline-grid';
        """) or False  # Default to False if not detected
        
        # Get padding and margin for various elements (divs, sections, headers, etc.)
        elements = WebDriverWait(driver, 10).until(
            EC.presence_of_all_elements_located((By.XPATH, "//body//*[self::div or self::section or self::header or self::footer]"))
        )
        total_padding = 0
        total_margin = 0
        
        for element in elements:
            padding = driver.execute_script("return window.getComputedStyle(arguments[0]).padding;", element) or '0px'
            margin = driver.execute_script("return window.getComputedStyle(arguments[0]).margin;", element) or '0px'
            
            # Process padding and margin values, ensuring they are numeric (skip 'auto' and non-numeric values)
            padding_values = list(map(clean_value, padding.split(' ')))
            margin_values = list(map(clean_value, margin.split(' ')))
            
            total_padding += sum(padding_values)
            total_margin += sum(margin_values)
        
        # Calculate whitespace as the percentage of total padding and margin relative to content area
        whitespace = (total_padding + total_margin) / (content_width * content_height) * 100
        
        # Dummy engagement metric (scroll depth, could be replaced with real data)
        scroll_depth = driver.execute_script("return window.scrollY;") / content_height * 100
        
        # Append data to the list
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
            "Whitespace (%)": whitespace,
            "Total Padding (px)": total_padding,
            "Total Margin (px)": total_margin
        })
    except Exception as e:
        print(f"Error scraping {site}: {e}")
        data.append({
            "Website": site,
            "Font Size": 'NULL',
            "Line Height": 'NULL',
            "Font Family": 'NULL',
            "Background Color": 'NULL',
            "Text Color": 'NULL',
            "Contrast Ratio": 0,
            "Content Width": 1,
            "Content Height": 1,
            "Scroll Depth (%)": 0,
            "Grid Layout": False,
            "Whitespace (%)": 0,
            "Total Padding (px)": 0,
            "Total Margin (px)": 0
        })

# Create a DataFrame
df = pd.DataFrame(data)

# Save the dataset to CSV
df.to_csv("web_design_metrics_extended.csv", index=False)

# Close the browser session
driver.quit()

print("Data collection completed.")
