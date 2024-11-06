import requests
import json
import sys
import re
from datetime import datetime

if __name__ == "__main__":
    assert(len(sys.argv) == 4)
    handle = sys.argv[1]
    token = sys.argv[2]
    readmePath = sys.argv[3]

    headers = {
        "Authorization": f"token {token}"
    }

    # Specify the correct repository here for commit fetching
    repo_name = "Hunterdii/GeeksforGeeks-POTD"  # Correct repo
    commit_url = f"https://api.github.com/repos/{repo_name}/commits?sha=main"
    
    # Fetch the latest commit for the correct repo
    response = requests.get(commit_url, headers=headers)

    if response.status_code != 200:
        print(f"Error fetching commit details: {response.text}")
        sys.exit(1)

    commit_data = response.json()[0]
    commit_sha = commit_data['sha']
    commit_message = commit_data['commit']['message']
    commit_date = commit_data['commit']['committer']['date']

    # Extract the question name or solution identifier from the commit message (example: "01(Nov) Solution Name")
    solution_identifier = commit_message.split(":")[0]  # Assuming commit message starts with the identifier

    # Define the daily solution file path (e.g., "01(Nov)question_name.md")
    solution_file_path = f"{solution_identifier}question_name.md"

    # Generate the badge URL dynamically based on the solution
    badge_url = f"https://img.shields.io/badge/Solution-{solution_identifier}-blue"
    badge_link = f"[![Today's Solution]({badge_url})](https://github.com/{handle}/{sys.argv[1]}/commit/{commit_sha})"
    
    # Prepare the commit link
    commit_link = f"Commit URL: https://github.com/{repo_name}/commit/{commit_sha}"

    # Update README with the new commit and badge
    with open(readmePath, "r") as readme:
        content = readme.read()

    # Update the commit link and the badge in the README file
    new_content = re.sub(r"(?<=<!--START_SECTION:latest-commit-->)[\s\S]*(?=<!--END_SECTION:latest-commit-->)", commit_link, content)
    new_content = re.sub(r"(?<=<!--START_SECTION:potd-badge-->)[\s\S]*(?=<!--END_SECTION:potd-badge-->)", badge_link, new_content)

    # Write the updated content back to README
    with open(readmePath, "w") as readme:
        readme.write(new_content)

    # Create or update the daily solution file (e.g., "01(Nov)question_name.md")
    with open(solution_file_path, "w") as solution_file:
        solution_file.write(f"# Solution for {solution_identifier}\n\nThis is the solution for {solution_identifier}. Commit link: [Commit]({commit_link})\n")
    
    print(f"Successfully updated README with the latest commit, badge, and created {solution_file_path}.")
