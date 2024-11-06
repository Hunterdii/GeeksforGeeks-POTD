import requests
import json
import sys
import re

if __name__ == "__main__":
    assert(len(sys.argv) == 3)  # Adjusted to take only the token and README path
    token = sys.argv[1]
    readmePath = sys.argv[2]

    headers = {
        "Authorization": f"token {token}"
    }

    # Set the target repository to the specific repo
    repo_name = "Hunterdii/GeeksforGeeks-POTD"  
    commit_url = f"https://api.github.com/repos/{repo_name}/commits?sha=main"
    
    # Fetch the latest commit details
    response = requests.get(commit_url, headers=headers)
    
    if response.status_code != 200:
        print(f"Error fetching commit details: {response.text}")
        sys.exit(1)

    commit_data = response.json()[0]
    commit_sha = commit_data['sha']
    commit_message = commit_data['commit']['message']
    commit_date = commit_data['commit']['committer']['date']
    
    # Extract the question name or solution identifier from the commit message
    solution_identifier = commit_message.split(":")[0]  # Assuming commit message starts with the identifier
    
    # Generate the badge URL dynamically based on the solution identifier
    badge_url = f"https://img.shields.io/badge/Solution-{solution_identifier}-blue"
    badge_link = f"[![Today's Solution]({badge_url})](https://github.com/{repo_name}/commit/{commit_sha})"
    
    # Prepare the commit link
    commit_link = f"Commit URL: https://github.com/{repo_name}/commit/{commit_sha}"

    # Update README with the new commit and badge
    with open(readmePath, "r") as readme:
        content = readme.read()

    # Update the commit link and the badge in the README file
    new_content = re.sub(r"(?<=<!--START_SECTION:latest-commit-->)[\s\S]*(?=<!--END_SECTION:latest-commit-->)", f" {commit_link} ", content)
    new_content = re.sub(r"(?<=<!--START_SECTION:potd-badge-->)[\s\S]*(?=<!--END_SECTION:potd-badge-->)", f" {badge_link} ", new_content)

    # Write the updated content back to README
    with open(readmePath, "w") as readme:
        readme.write(new_content)

    print("Successfully updated README with the latest commit and badge.")
