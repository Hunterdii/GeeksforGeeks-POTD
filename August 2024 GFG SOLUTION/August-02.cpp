//{ Diver Code Starts
#include <bits/stdc++.h>
using namespace std;

// ] Driver Code ends
class Solution
{
public:
    int editDistance(std::string str1, std::string str2)
    {
        int m = str1.length();
        int k = str2.length();

        // Create a 2D DP array
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(k + 1, 0));

        // Fill dp array
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                // If first string is empty, insert all characters of second string
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                // If second string is empty, remove all characters of first string
                else if (j == 0)
                {
                    dp[i][j] = i;
                }
                // If last characters are the same, ignore last char and recur for remaining string
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // If last character is different, consider all possibilities and find the minimum
                else
                {
                    dp[i][j] = 1 + std::min({
                                       dp[i - 1][j],    // Remove
                                       dp[i][j - 1],    // Insert
                                       dp[i - 1][j - 1] // Replace
                                   });
                }
            }
        }
        return dp[m][k];
    }
};

//{ Driver Code Starts .
int main()
{
    int T;
    cin >> T while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
