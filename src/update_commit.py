import requests
import sys
import os
import re  # This is missing in your original script
from datetime import datetime

def get_latest_solution_file(directory: str):
    # Get all files in the directory
    files = os.listdir(directory)
    
    # Filter out only the files that match the date format for solutions (e.g., 06(Nov).md)
    solution_files = [file for file in files if file.endswith('.md') and re.match(r"\d{2}\([A-Za-z]{3}\).+\.md", file)]
    
    # Sort the files based on date, assuming filenames are in the format "DD(Month)Name.md"
    solution_files.sort(key=lambda f: datetime.strptime(f[:6], "%d(%b)"))
    
    # Return the most recent file
    return solution_files[-1] if solution_files else None

if __name__ == "__main__":
    assert(len(sys.argv) == 4)
    repository = sys.argv[1]
    token = sys.argv[2]
    readme_path = sys.argv[3]

    # Path where your solutions are stored
    solution_dir = "November 2024 GFG SOLUTION"
    
    # Get the latest solution filename
    latest_solution_file = get_latest_solution_file(solution_dir)
    if not latest_solution_file:
        raise Exception("No solution files found!")
    
    # Extract the day and month from the file name (e.g., 06(Nov))
    day_of_month = latest_solution_file[:2]
    month = latest_solution_file[3:6]
    
    # Prepare the solution URL
    solution_url = f"https://raw.githubusercontent.com/{repository}/main/{solution_dir}/{latest_solution_file}"
    
    # Prepare the badge URL and commit link to update README
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})]({solution_url})"  # This makes the badge link to the solution for today

    # Read the README file and update the sections for commit and badge
    with open(readme_path, "r") as readme:
        content = readme.read()

    # Update badge link
    content = re.sub(
        r"(?<=<!--START_SECTION:potd-badge-->).*?(?=<!--END_SECTION:potd-badge-->)", 
        f"\n{badge_link}\n", 
        content, 
        flags=re.DOTALL
    )

    # Write the updated content back to the README
    with open(readme_path, "w") as readme:
        readme.write(content)
