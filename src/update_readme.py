import sys
import re
import requests

def fetch_latest_commit(repo, token, file_pattern):
    headers = {"Authorization": f"token {token}"}
    url = f"https://api.github.com/repos/{repo}/commits"
    params = {"path": file_pattern, "per_page": 1}
    response = requests.get(url, headers=headers, params=params)
    
    if response.ok and response.json():
        commit_data = response.json()[0]
        commit_url = commit_data["html_url"]
        return commit_url
    else:
        print("Error fetching commit data:", response.status_code, response.text)
        sys.exit(1)

def update_readme(readme_path, commit_url):
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})]({commit_url})"
    
    with open(readme_path, "r") as file:
        content = file.read()
        
    new_content = re.sub(
        r"(?<=<!--START_SECTION:latest-commit-->)[\s\S]*(?=<!--END_SECTION:latest-commit-->)",
        f"\n{commit_url}\n",
        content
    )
    
    new_content = re.sub(
        r"(?<=<!--START_SECTION:potd-badge-->)[\s\S]*(?=<!--END_SECTION:potd-badge-->)",
        f"\n{badge_link}\n",
        new_content
    )

    with open(readme_path, "w") as file:
        file.write(new_content)

if __name__ == "__main__":
    repo = sys.argv[1]
    token = sys.argv[2]
    readme_path = sys.argv[3]
    file_pattern = sys.argv[4]  # Example pattern: "01(Nov)question name.md"
    
    commit_url = fetch_latest_commit(repo, token, file_pattern)
    update_readme(readme_path, commit_url)
