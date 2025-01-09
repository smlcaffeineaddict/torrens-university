from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
import pandas as pd

# List of 50 websites to scrape (this can be expanded)
websites = [
    "https://monogrid.com", "https://www.media.monks.com", "https://activetheory.net",
    "https://heydays.no", "https://joancreative.com", "https://www.mirimarus.com",
    # Add remaining 44 websites here
]

# Data storage
data = []

# Initialize the Chrome WebDriver with WebDriver Manager
options = webdriver.ChromeOptions()
options.add_argument("user-data-dir=/tmp/chrome_user_data")  # Optional: Use custom user data directory
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)

# Loop through websites to collect metrics
for site in websites:
    driver.get(site)
    
    try:
        # Collect typography metrics
        font_size = driver.execute_script("return window.getComputedStyle(document.body).fontSize;")
        line_height = driver.execute_script("return window.getComputedStyle(document.body).lineHeight;")
        
        # Collect color metrics (example: background color)
        background_color = driver.execute_script("return window.getComputedStyle(document.body).backgroundColor;")
        
        # Collect layout metrics (example: grid column count, whitespace percentage)
        content_width = driver.execute_script("return document.body.clientWidth;")
        content_height = driver.execute_script("return document.body.clientHeight;")
        
        # Dummy engagement metric (scroll depth, could be replaced with real data)
        scroll_depth = driver.execute_script("return window.scrollY;") / content_height * 100
        
        # Append data to the list
        data.append({
            "Website": site,
            "Font Size": font_size,
            "Line Height": line_height,
            "Background Color": background_color,
            "Content Width": content_width,
            "Content Height": content_height,
            "Scroll Depth (%)": scroll_depth
        })
    except Exception as e:
        print(f"Error scraping {site}: {e}")

# Create a DataFrame
df = pd.DataFrame(data)

# Save the dataset to CSV
df.to_csv("web_design_metrics.csv", index=False)
driver.quit()

print("Data collection completed.")
