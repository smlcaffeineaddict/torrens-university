import subprocess
import os

# Function to run a Python script and handle errors
def run_script(script_name):
    try:
        print(f"Running {script_name}...")
        result = subprocess.run(['python', script_name], check=True, capture_output=True, text=True)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"Error running {script_name}: {e}")
        print(e.output)

# Step 1: Run the data collection script
print("Step 1: Running data collection...")
run_script('data-collection.py')

# Step 2: Run the data cleaning script
print("Step 2: Running data cleaning...")
run_script('data-clean.py')

# Step 3: Run the descriptive statistics script
print("Step 3: Running descriptive statistics...")
run_script('descriptive-statistics.py')

# Step 4: Run the data analysis script
print("Step 4: Running data analysis...")
run_script('data-analysis.py')

print("All steps completed successfully.")
