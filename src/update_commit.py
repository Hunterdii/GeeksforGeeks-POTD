import requests
import sys
import re
from datetime import datetime

if __name__ == "__main__":
    assert(len(sys.argv) == 4)
    repository = sys.argv[1]
    token = sys.argv[2]
    readme_path = sys.argv[3]

    headers = {
        "Authorization": f"token {token}"
    }

    # Get the current date
    today = datetime.today()
    day_of_month = today.strftime("%d")  # Get current day of the month (e.g., 06)
    month = today.strftime("%b")  # Get current month (e.g., Nov)

    # Generate the filename based on the day of the month (e.g., 06(Nov) Root to leaf paths sum.md)
    today_solution_filename = f"{day_of_month}({month})"  # The pattern that matches the filename format.

    # Make a request to GitHub to list files in the directory
    dir_url = f"https://api.github.com/repos/{repository}/contents/{month}%202024%20GFG%20SOLUTION"
    response = requests.get(dir_url, headers=headers)
    
    if not response.ok:
        print(f"Failed to fetch files: {response.status_code} {response.text}")
        sys.exit(1)
    
    files = response.json()

    # Check if files are empty or response is not valid
    if isinstance(files, dict) and files.get('message') == 'Not Found':
        print(f"Directory not found: {dir_url}")
        sys.exit(1)

    # Search for the correct file based on the date
    today_file = None
    for file in files:
        if file['name'].startswith(today_solution_filename):
            today_file = file['name']
            break
    
    if not today_file:
        print(f"No solution file found for {today_solution_filename}. Please check the directory.")
        sys.exit(1)

    # Prepare the correct file URL based on the found filename
    solution_url = f"https://github.com/{repository}/blob/main/{month}%202024%20GFG%20SOLUTION/{today_file}"

    # Prepare the badge URL with the correct link to today's solution
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})]({solution_url})"

    # Read the README file and update the sections for the badge
    with open(readme_path, "r") as readme:
        content = readme.read()

    # Update the badge with the dynamic link to today's solution
    content = re.sub(
        r"(?<=<!--START_SECTION:potd-badge-->).*?(?=<!--END_SECTION:potd-badge-->)", 
        f"\n{badge_link}\n", 
        content, 
        flags=re.DOTALL
    )

    # Write the updated content back to the README
    with open(readme_path, "w") as readme:
        readme.write(content)
