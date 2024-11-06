import requests
import sys
import re

if __name__ == "__main__":
    assert(len(sys.argv) == 4)
    repository = sys.argv[1]
    token = sys.argv[2]
    readme_path = sys.argv[3]

    headers = {
        "Authorization": f"token {token}"
    }

    # Get the latest commit of the day for the repository
    commit_url = f"https://api.github.com/repos/{repository}/commits"
    response = requests.get(commit_url, headers=headers)
    
    if not response.ok:
        print(f"Failed to fetch commits: {response.status_code} {response.text}")
        sys.exit(1)
    
    commits = response.json()
    
    # Assuming the first commit in the list is the most recent commit
    latest_commit = commits[0]
    commit_sha = latest_commit['sha']
    commit_link = f"https://github.com/{repository}/commit/{commit_sha}"

    # Prepare the badge URL and commit link to update README
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})](https://github.com/{repository})"

    # Read the README file and update the sections for commit and badge
    with open(readme_path, "r") as readme:
        content = readme.read()

    # Update commit link
    content = re.sub(
        r"(?<=<!--START_SECTION:latest-commit-->).*?(?=<!--END_SECTION:latest-commit-->)", 
        f"\n{commit_link}\n", 
        content, 
        flags=re.DOTALL
    )
    
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
