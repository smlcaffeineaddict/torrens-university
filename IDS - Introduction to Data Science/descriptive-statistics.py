import pandas as pd

# Load the cleaned dataset from data-clean.py
df = pd.read_csv('web_design_metrics_cleaned_extended.csv')

# 1. Descriptive Statistics: Get the mean, median, std deviation, and percentiles for numeric columns
descriptive_stats = df[['Font Size', 'Line Height', 'Content Width', 'Scroll Depth (%)', 
                        'Total Padding (px)', 'Total Margin (px)', 'Contrast Ratio', 'Whitespace (%)']].describe()

# 2. For categorical columns like 'Grid Layout' (True/False), calculate the most common value
categorical_stats = {
    'Grid Layout': df['Grid Layout'].mode()[0],  # Most common value (True/False)
}

# Combine the numeric and categorical statistics into one DataFrame for easier comparison
final_descriptive_stats = pd.DataFrame.from_dict(categorical_stats, orient='index', columns=['Most Common'])

# Use pd.concat instead of append to combine the data
final_descriptive_stats = pd.concat([final_descriptive_stats, descriptive_stats])

# 3. Save the descriptive statistics to a CSV file for later use
final_descriptive_stats.to_csv('descriptive_statistics_for_analysis.csv')

print("Descriptive statistics have been calculated and saved to 'descriptive_statistics_for_analysis.csv'.")
