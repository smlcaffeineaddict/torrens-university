import pandas as pd
import re

# Load the dataset collected by data-collection.py
df = pd.read_csv("web_design_metrics_extended.csv")

# Function to clean non-numeric values (remove unwanted characters like 'px', 'auto', and parentheses)
def clean_value(value):
    # Remove unwanted characters like 'px', 'auto', parentheses, etc.
    cleaned_value = re.sub(r'[^\d.]', '', str(value))  # Keep only digits and periods
    return float(cleaned_value) if cleaned_value else 0  # Return 0 if cleaned_value is empty

# Apply the clean_value function to the columns that require it
df['Font Size'] = df['Font Size'].apply(clean_value)
df['Line Height'] = df['Line Height'].apply(clean_value)
df['Content Width'] = df['Content Width'].apply(clean_value)
df['Scroll Depth (%)'] = df['Scroll Depth (%)'].apply(clean_value)
df['Total Padding (px)'] = df['Total Padding (px)'].apply(clean_value)
df['Total Margin (px)'] = df['Total Margin (px)'].apply(clean_value)

# Handle missing values (replace NULL or any non-numeric value with 0)
df.fillna({
    'Font Size': 0,
    'Line Height': 0,
    'Content Width': 0,
    'Scroll Depth (%)': 0,
    'Total Padding (px)': 0,
    'Total Margin (px)': 0,
    'Contrast Ratio': 0,
    'Grid Layout': False,
    'Whitespace (%)': 0
}, inplace=True)

# Handle the 'Contrast Ratio' column - ensure it's a valid float, default to 0 if invalid
df['Contrast Ratio'] = pd.to_numeric(df['Contrast Ratio'], errors='coerce').fillna(0)

# Save the cleaned dataset to a new CSV file
df.to_csv("web_design_metrics_cleaned_extended.csv", index=False)

print("Data cleaning completed and saved to 'web_design_metrics_cleaned_extended.csv'.")
