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
    day_of_month = today.strftime("%d")  # Get current day of the month
    month = today.strftime("%b")  # Get current month (e.g., Nov)
    
    # Format the solution file name for today (e.g., 07(Nov)Next Problem.md)
    today_solution_filename = f"{day_of_month}({month}){today.strftime('%A')}.md"

    # Prepare the badge URL and commit link to update README
    badge_url = "https://img.shields.io/badge/GeeksforGeeks-Solution%20of%20the%20Day-blue"
    badge_link = f"[![Today's POTD Solution]({badge_url})](https://github.com/{repository}/blob/main/{month}%202024%20GFG%20SOLUTION/{today_solution_filename})"

    # Read the README file and update the sections for commit and badge
    with open(readme_path, "r") as readme:
        content = readme.read()

    # Update today's solution link
    content = re.sub(
        r"(?<=<!--START_SECTION:latest-commit-->).*?(?=<!--END_SECTION:latest-commit-->)", 
        f"\nhttps://github.com/{repository}/blob/main/{month}%202024%20GFG%20SOLUTION/{today_solution_filename}\n", 
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
