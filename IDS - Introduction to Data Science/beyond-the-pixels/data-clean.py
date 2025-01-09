import pandas as pd
import re

pd.set_option('future.no_silent_downcasting', True)

# Load the dataset
try:
    df = pd.read_csv("web_design_metrics.csv")
    print("Dataset loaded successfully.")
except Exception as e:
    print(f"Error loading CSV: {e}")
except FileNotFoundError:
    print("Error: Dataset not found. Ensure 'web_design_metrics.csv' is in the current directory.")
    exit()

# Function to clean numeric columns and round to three decimal places
def clean_numeric_value(value, decimal_places=3):
    """Clean and convert values to float, preserving decimal points."""
    if isinstance(value, str):
        # Remove any non-numeric characters except the decimal point
        cleaned_value = re.sub(r'[^0-9.]', '', value)
        try:
            # Return the cleaned value as a float rounded to the specified decimal places
            return round(float(cleaned_value), decimal_places) if cleaned_value else 0
        except ValueError:
            return 0  # Return 0 if the value can't be converted to a float
    return round(value, decimal_places)  # Apply rounding for numeric values directly

# Function to clean string columns
def clean_string_column(column):
    """Clean string columns, strip leading/trailing spaces, and replace NaN with 'Unknown'."""
    return column.fillna('Unknown').str.strip()

# Apply cleaning operations
try:
    # Clean the numeric columns (e.g., Font Size, Line Height, Contrast Ratio, etc.)
    df['Font Size'] = df['Font Size'].apply(clean_numeric_value)  # e.g., '14px' becomes 14
    df['Line Height'] = df['Line Height'].apply(clean_numeric_value)  # e.g., '16.1px' becomes 16.1
    df['Content Width'] = df['Content Width'].apply(clean_numeric_value)
    df['Content Height'] = df['Content Height'].apply(clean_numeric_value)
    df['Scroll Depth (%)'] = df['Scroll Depth (%)'].apply(clean_numeric_value)
    df['Contrast Ratio'] = df['Contrast Ratio'].apply(clean_numeric_value)
    df['Total Padding'] = df['Total Padding'].apply(clean_numeric_value)

    # Clean the string columns (e.g., Font Family, Background Color, etc.)
    df['Font Family'] = clean_string_column(df['Font Family'])
    df['Background Color'] = clean_string_column(df['Background Color'])
    df['Text Color'] = clean_string_column(df['Text Color'])
    df['Grid Layout'] = df['Grid Layout'].fillna(False).astype(bool)  # Convert 'Grid Layout' to boolean
    df['Error'] = clean_string_column(df['Error'])  # Clean the Error column as well

    print("Data cleaning completed.")

except Exception as e:
    print(f"An error occurred during cleaning: {e}")
    exit()

# Save the cleaned dataset
cleaned_file_name = "web_design_metrics_cleaned.csv"
df.to_csv(cleaned_file_name, index=False)
print(f"Cleaned dataset saved as {cleaned_file_name}.")