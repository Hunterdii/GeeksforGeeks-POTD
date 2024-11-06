import requests
import sys
import re

# GitHub API to fetch the latest commit
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

    # Extract the latest commit's file name and URL
    commit_message = commit_data["commit"]["message"]
    commit_date = commit_data["commit"]["committer"]["date"]
    
    # Assume the file is in the `GFG SOLUTION` folder and match the file name based on the commit message (assuming this naming convention is consistent)
    solution_filename = commit_message.strip().replace(" ", "%20") + ".md"
    
    # Construct the solution URL
    solution_url = f"https://github.com/{repository}/blob/main/November%202024%20GFG%20SOLUTION/{solution_filename}"

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
