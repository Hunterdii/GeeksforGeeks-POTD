import requests
import sys
import re
from datetime import datetime

if __name__ == "__main__":
    assert(len(sys.argv) == 4)
    repository = sys.argv[1]
    token = sys.argv[2]
    readme_path = sys.argv[3]

    # GitHub API to get the latest commit from the repository
    api_url = f"https://api.github.com/repos/{repository}/commits"
    
    headers = {
        "Authorization": f"token {token}"
    }

    # Get the latest commit
    response = requests.get(api_url, headers=headers)
    if response.status_code != 200:
        raise Exception(f"Error fetching commits: {response.status_code}, {response.text}")
    
    commits = response.json()
    latest_commit = commits[0]  # Get the most recent commit

    # Extract the commit date and message
    commit_date = latest_commit['commit']['author']['date']
    commit_message = latest_commit['commit']['message']

    # Extract the solution filename from the commit message (assumed format)
    # Example: 'Add solution for 07(Nov) Insert in Sorted way in a Sorted DLL'
    # We need to extract the file name: '07(Nov) Insert in Sorted way in a Sorted DLL.md'
    
    # The commit message is expected to have the solution's file name in a consistent format.
    solution_filename = f"{commit_message.split(' ')[-1]}.md"
    
    # Prepare the solution URL based on the commit
    today = datetime.today()
    month = today.strftime("%b")  # Current month (e.g., Nov)

    solution_url = f"https://github.com/{repository}/blob/main/{month}%202024%20GFG%20SOLUTION/{solution_filename}"

    # Prepare the badge URL and commit link to update README
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})]({solution_url})"  # This makes the badge link to the solution

    # Read the README file and update the sections for the badge
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
