//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the nth character in the modified string.
    // Parameters:
    //   s: The original string.
    //   r: The number of iterations to perform the modification.
    //   n: The index of the character to return in the modified string.
    // Returns:
    //   The nth character in the modified string after r iterations.
    char nthCharacter(string s, int r, int n) {
        int len = s.length();  // Length of the original string.
        
        // Perform r iterations.
        for (int i = 0; i < r; i++) {
            string temp = s;  // Create a temporary string to hold the modified version.
            
            // Iterate through each character in the string.
            for (int j = 0; j < len; j++) {
                // Modify the character based on its position and the original value.
                if (temp[j / 2] == '0')
                    s[j] = '0' + (j % 2);
                else
                    s[j] = '1' - (j % 2);
            }
        }
        
        // Return the nth character in the modified string.
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
