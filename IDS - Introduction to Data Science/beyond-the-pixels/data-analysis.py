import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load the cleaned dataset
try:
    df = pd.read_csv("web_design_metrics_cleaned.csv")
    print("Dataset loaded successfully.")
except Exception as e:
    print(f"Error loading CSV: {e}")
    exit()

# 1. Plot Font Size Distribution
def plot_font_size_distribution(df):
    plt.figure(figsize=(10, 6))
    sns.histplot(df['Font Size'], bins=20, kde=True)
    plt.title('Font Size Distribution')
    plt.xlabel('Font Size (px)')
    plt.ylabel('Frequency')
    plt.tight_layout()
    plt.savefig('font_size_distribution.png')
    plt.show()

# 2. Plot Line Height Distribution
def plot_line_height_distribution(df):
    plt.figure(figsize=(10, 6))
    sns.histplot(df['Line Height'], bins=20, kde=True)
    plt.title('Line Height Distribution')
    plt.xlabel('Line Height (px)')
    plt.ylabel('Frequency')
    plt.tight_layout()
    plt.savefig('line_height_distribution.png')
    plt.show()

# 3. Plot Contrast Ratio
def plot_contrast_ratio(df):
    plt.figure(figsize=(10, 6))
    sns.histplot(df['Contrast Ratio'], bins=20, kde=True)
    plt.title('Contrast Ratio Distribution')
    plt.xlabel('Contrast Ratio')
    plt.ylabel('Frequency')
    plt.tight_layout()
    plt.savefig('contrast_ratio_distribution.png')
    plt.show()

# 4. Plot Scroll Depth vs. Content Width
def plot_scroll_depth_vs_content_width(df):
    plt.figure(figsize=(10, 6))
    sns.scatterplot(x='Content Width', y='Scroll Depth (%)', data=df)
    plt.title('Scroll Depth vs. Content Width')
    plt.xlabel('Content Width (px)')
    plt.ylabel('Scroll Depth (%)')
    plt.tight_layout()
    plt.savefig('scroll_depth_vs_content_width.png')
    plt.show()

# 5. Plot Grid Layout vs. Scroll Depth
def plot_grid_layout_vs_scroll_depth(df):
    plt.figure(figsize=(10, 6))
    sns.boxplot(x='Grid Layout', y='Scroll Depth (%)', data=df)
    plt.title('Grid Layout vs. Scroll Depth')
    plt.xlabel('Grid Layout')
    plt.ylabel('Scroll Depth (%)')
    plt.tight_layout()
    plt.savefig('grid_layout_vs_scroll_depth.png')
    plt.show()

# 6. Plot Correlation Heatmap
def plot_correlation_heatmap(df):
    # Select only numeric columns for correlation calculation
    numeric_df = df.select_dtypes(include=['number'])
    plt.figure(figsize=(12, 8))
    corr = numeric_df.corr()  # Compute correlation only for numeric columns
    sns.heatmap(corr, annot=True, cmap="coolwarm", fmt=".2f", linewidths=0.5)
    plt.title('Correlation Heatmap')
    plt.tight_layout()
    plt.savefig('correlation_heatmap.png')
    plt.show()

# 7. Plot Most Common Font Families
def plot_most_common_font_families(df):
    font_family_counts = df['Font Family'].value_counts().head(10)
    plt.figure(figsize=(10, 6))
    font_family_counts.plot(kind='bar')
    plt.title('Top 10 Most Common Font Families')
    plt.xlabel('Font Family')
    plt.ylabel('Count')
    plt.tight_layout()
    plt.savefig('most_common_font_families.png')
    plt.show()

# Call the functions to generate the figures
plot_font_size_distribution(df)
plot_line_height_distribution(df)
plot_contrast_ratio(df)
plot_scroll_depth_vs_content_width(df)
plot_grid_layout_vs_scroll_depth(df)
plot_correlation_heatmap(df)
plot_most_common_font_families(df)

print("Data analysis and figure generation completed.")
