import requests
import sys
import re

def get_latest_commit(repo):
    url = f"https://api.github.com/repos/{repo}/commits"
    response = requests.get(url)
    if response.status_code != 200:
        raise Exception(f"Failed to fetch commits: {response.status_code}, {response.text}")
    latest_commit = response.json()[0]
    commit_url = latest_commit["html_url"]
    commit_message = latest_commit["commit"]["message"]
    return commit_url, commit_message

def update_readme(readme_path, commit_url, commit_message):
    with open(readme_path, "r") as file:
        content = file.read()

    # Construct badge and link
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})](https://github.com/Hunterdii/GeeksforGeeks-POTD)"

    # Update the sections in the README
    updated_content = re.sub(
        r"(?<=<!\-\-START_SECTION:latest\-commit\-\->)[\s\S]*(?=<!\-\-END_SECTION:latest\-commit\-\->)",
        f"\n{commit_url}\n",
        content
    )
    updated_content = re.sub(
        r"(?<=<!\-\-START_SECTION:potd\-badge\-\->)[\s\S]*(?=<!\-\-END_SECTION:potd\-badge\-\->)",
        f"\n{badge_link}\n",
        updated_content
    )

    with open(readme_path, "w") as file:
        file.write(updated_content)

if __name__ == "__main__":
    repo = sys.argv[1]
    readme_path = sys.argv[2]
    
    commit_url, commit_message = get_latest_commit(repo)
    update_readme(readme_path, commit_url, commit_message)
