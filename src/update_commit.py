import requests
import sys
import re
from datetime import datetime

if __name__ == "__main__":
    assert(len(sys.argv) == 4)
    repository = sys.argv[1]
    token = sys.argv[2]
    readme_path = sys.argv[3]

    # GitHub API URL to get the latest commit info from the default branch (main)
    api_url = f"https://api.github.com/repos/{repository}/commits/main"

    # Make the API request
    headers = {
        "Authorization": f"token {token}"
    }

    response = requests.get(api_url, headers=headers)

    # Check if the request is successful
    if response.status_code != 200:
        print(f"Error fetching latest commit: {response.json()}")
        sys.exit(1)

    # Parse the response to get the latest commit's file name
    commit_data = response.json()
    commit_files = commit_data["files"]
    
    # Loop through the files to find the solution file (only considering files in the November folder)
    solution_filename = ""
    for file in commit_files:
        filename = file["filename"]
        if "November%202024%20GFG%20SOLUTION" in filename:
            solution_filename = filename
            break

    if not solution_filename:
        print("Solution file not found for today's date.")
        sys.exit(1)

    # Construct the solution URL for the current solution
    solution_url = f"https://raw.githubusercontent.com/{repository}/main/{solution_filename}"

    # Prepare the badge URL and commit link to update README
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})]({solution_url})"  # This makes the badge link to the solution for today

    # Read the README file and update the sections for the badge link
    with open(readme_path, "r") as readme:
        content = readme.read()

    # Update the badge link in the README
    content = re.sub(
        r"(?<=<!--START_SECTION:potd-badge-->).*?(?=<!--END_SECTION:potd-badge-->)", 
        f"\n{badge_link}\n", 
        content, 
        flags=re.DOTALL
    )

    # Write the updated content back to the README
    with open(readme_path, "w") as readme:
        readme.write(content)
