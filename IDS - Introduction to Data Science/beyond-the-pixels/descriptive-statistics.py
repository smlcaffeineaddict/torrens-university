import pandas as pd

# Load the cleaned dataset
try:
    df = pd.read_csv("web_design_metrics_cleaned.csv")
    print("Dataset loaded successfully.")
except Exception as e:
    print(f"Error loading CSV: {e}")
    exit()

# Function to calculate descriptive statistics for numeric columns
def calculate_numeric_stats(df):
    # Get descriptive statistics for numeric columns
    numeric_cols = df.select_dtypes(include='number').columns
    numeric_stats = df[numeric_cols].describe().transpose()

    # Round the numeric statistics to 2 decimal places
    numeric_stats = numeric_stats.round(2)
    
    return numeric_stats

# Function to calculate most common values for categorical columns
def calculate_categorical_stats(df):
    # Get most frequent value for categorical columns
    categorical_cols = df.select_dtypes(include='object').columns
    categorical_stats = df[categorical_cols].agg(lambda x: x.value_counts().idxmax()).to_frame(name="Most Common")
    return categorical_stats

# Calculate statistics
numeric_stats = calculate_numeric_stats(df)
categorical_stats = calculate_categorical_stats(df)

# Combine the numeric and categorical statistics into one DataFrame for easier comparison
final_stats = pd.concat([numeric_stats, categorical_stats], axis=1)

# Save the descriptive statistics to a CSV file for later use
output_file = "descriptive_statistics_for_analysis.csv"
final_stats.to_csv(output_file)

print(f"Descriptive statistics saved as {output_file}.")
