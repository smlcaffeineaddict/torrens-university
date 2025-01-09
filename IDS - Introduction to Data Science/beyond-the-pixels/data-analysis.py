import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load the cleaned dataset from data-clean.py
df = pd.read_csv('web_design_metrics_cleaned_extended.csv')

# Set up the plot style for better visualization
sns.set(style="whitegrid")

# 1. Descriptive statistics (already computed and stored in previous scripts)
# df['Font Size', 'Line Height', etc. are already cleaned

# 2. Correlation heatmap for numerical values
plt.figure(figsize=(10, 8))
correlation_matrix = df[['Font Size', 'Line Height', 'Content Width', 'Scroll Depth (%)',
                         'Total Padding (px)', 'Total Margin (px)', 'Contrast Ratio', 'Whitespace (%)']].corr()
sns.heatmap(correlation_matrix, annot=True, cmap="coolwarm", fmt=".2f", linewidths=0.5)
plt.title('Correlation Heatmap of Web Design Metrics')
plt.tight_layout()
plt.savefig("correlation_heatmap.png")
plt.show()

# 3. Distribution of font sizes
plt.figure(figsize=(8, 6))
sns.histplot(df['Font Size'], kde=True, color='blue', bins=10)
plt.title('Distribution of Font Size')
plt.xlabel('Font Size (px)')
plt.ylabel('Frequency')
plt.tight_layout()
plt.savefig("font_size_distribution.png")
plt.show()

# 4. Boxplot: Distribution of line height across different font sizes
plt.figure(figsize=(8, 6))
sns.boxplot(x='Font Size', y='Line Height', data=df, palette="Set2")
plt.title('Line Height Distribution Across Font Sizes')
plt.xlabel('Font Size (px)')
plt.ylabel('Line Height (px)')
plt.tight_layout()
plt.savefig("line_height_distribution.png")
plt.show()

# 5. Contrast ratio vs. font size (Scatter plot)
plt.figure(figsize=(8, 6))
sns.scatterplot(x='Font Size', y='Contrast Ratio', data=df, color='green')
plt.title('Contrast Ratio vs. Font Size')
plt.xlabel('Font Size (px)')
plt.ylabel('Contrast Ratio')
plt.tight_layout()
plt.savefig("contrast_vs_font_size.png")
plt.show()

# 6. Bar plot: Grid Layout usage
grid_layout_counts = df['Grid Layout'].value_counts()
plt.figure(figsize=(8, 6))
sns.barplot(x=grid_layout_counts.index, y=grid_layout_counts.values, palette="Blues")
plt.title('Grid Layout Usage')
plt.xlabel('Grid Layout (True/False)')
plt.ylabel('Count')
plt.tight_layout()
plt.savefig("grid_layout_usage.png")
plt.show()

# 7. Whitespace distribution vs. content width (Scatter plot)
plt.figure(figsize=(8, 6))
sns.scatterplot(x='Content Width', y='Whitespace (%)', data=df, color='red')
plt.title('Whitespace Distribution vs. Content Width')
plt.xlabel('Content Width (px)')
plt.ylabel('Whitespace (%)')
plt.tight_layout()
plt.savefig("whitespace_vs_content_width.png")
plt.show()

# 8. Scroll depth distribution (Histogram)
plt.figure(figsize=(8, 6))
sns.histplot(df['Scroll Depth (%)'], kde=True, color='purple', bins=10)
plt.title('Scroll Depth Distribution')
plt.xlabel('Scroll Depth (%)')
plt.ylabel('Frequency')
plt.tight_layout()
plt.savefig("scroll_depth_distribution.png")
plt.show()

# 9. Pairplot for major metrics to understand relationships
sns.pairplot(df[['Font Size', 'Line Height', 'Scroll Depth (%)', 'Contrast Ratio', 'Whitespace (%)']])
plt.suptitle('Pairplot of Key Web Design Metrics', y=1.02)
plt.tight_layout()
plt.savefig("pairplot.png")
plt.show()

# Saving summary statistics as CSV for future reference
summary_stats = df[['Font Size', 'Line Height', 'Content Width', 'Scroll Depth (%)',
                    'Total Padding (px)', 'Total Margin (px)', 'Contrast Ratio', 'Whitespace (%)']].describe()
summary_stats.to_csv("summary_statistics.csv")

print("Data analysis completed and figures saved.")
