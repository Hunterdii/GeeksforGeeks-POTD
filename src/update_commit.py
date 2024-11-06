import requests
import sys
import re

# GitHub API to fetch the latest commit and changed files
GITHUB_API_URL = "https://api.github.com"

if __name__ == "__main__":
    assert(len(sys.argv) == 4)
    repository = sys.argv[1]
    token = sys.argv[2]
    readme_path = sys.argv[3]

    # Fetch the latest commit information for the repository
    commits_url = f"{GITHUB_API_URL}/repos/{repository}/commits?per_page=1"
    headers = {"Authorization": f"token {token}"}
    response = requests.get(commits_url, headers=headers)
    response.raise_for_status()
    commit_data = response.json()[0]  # Get the latest commit

    # Fetch the list of changed files in the latest commit
    files_url = commit_data["url"] + "/files"
    response = requests.get(files_url, headers=headers)
    response.raise_for_status()
    files = response.json()

    # Find the solution file from the changed files (based on the folder and expected filename format)
    solution_filename = None
    for file in files:
        # Check if the file is in the "November 2024 GFG SOLUTION" folder and matches the filename pattern
        if "November 2024 GFG SOLUTION" in file["filename"]:
            solution_filename = file["filename"]
            break

    if not solution_filename:
        raise ValueError("No valid solution file found in the latest commit.")

    # Prepare the solution URL based on the file path
    solution_url = f"https://github.com/{repository}/blob/main/{solution_filename}"

    # Prepare the badge URL and commit link to update README
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})]({solution_url})"  # This makes the badge link to the solution

    # Read the README file and update the sections for the commit and badge
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
