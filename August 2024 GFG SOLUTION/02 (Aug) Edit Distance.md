\#\# 02\. Edit Distance

The problem can be found at the following link: \[Question Link\](https://www.geeksforgeeks.org/problems/edit-distance3702/1)

\#\#\# Problem Description

Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.  
The possible operations are permitted:

1.Insert a character at any position of the string.  
2.Remove any character from the string.  
3.Replace any character from the string with any other character.

\*\*Example:\*\*

Input: str1 \= "geek", srt2 \= "gesek"  
Output: 1  
Explanation: One operation is required, inserting 's' between two 'e'.  
\`\`\`  
Input : str1 \= "gfg", str2 \= "gfg"  
Output: 0  
Explanation: Both strings are same.  
\`\`\`

\#\#\# My Approach

Steps:

#### **Steps:**

1. **Initialization**:  
   * Create a 2D array `dp` where `dp[i][j]` will store the minimum number of operations required to convert the first `i` characters of `str1` into the first `j` characters of `str2`.  
1. **Base Cases**:  
   * If one of the strings is empty:  
     * To transform an empty `str1` into `str2` (of length `j`), we need `j` insertions.  
     * To transform `str1` (of length `i`) into an empty `str2`, we need `i` deletions.  
1. **Filling the DP Table**:  
   * For each pair of characters from `str1` and `str2` (at positions `i-1` and `j-1`):  
     * If the characters are the same, no new operation is needed, so we carry forward the value from `dp[i-1][j-1]`.  
     * If the characters are different, we consider the three possible operations:  
       * **Insert**: We consider the cost of inserting the character, which is `dp[i][j-1] + 1`.  
       * **Remove**: We consider the cost of removing a character, which is `dp[i-1][j] + 1`.  
       * **Replace**: We consider the cost of replacing a character, which is `dp[i-1][j-1] + 1`.  
   * We take the minimum of these three operations and store it in `dp[i][j]`.  
1. **Result**:  
   * The value in `dp[len(str1)][len(str2)]` gives us the minimum number of operations needed to convert `str1` into `str2`.

\#\#\# Time and Auxiliary Space Complexity

Expected Time Complexity: O(|str1|\*|str2|)  
Expected Space Complexity: O(|str1|\*|str2|)

\#\#\# Code (C++)

\`\`\`cpp  
class Solution  
{  
public:  
    int editDistance(std::string str1, std::string str2)  
    {  
        int m \= str1.length();  
        int k \= str2.length();

        // Create a 2D DP array  
        std::vector\<std::vector\<int\>\> dp(m \+ 1, std::vector\<int\>(k \+ 1, 0));

        // Fill dp array  
        for (int i \= 0; i \<= m; \++i)  
        {  
            for (int j \= 0; j \<= k; \++j)  
            {  
                // If first string is empty, insert all characters of second string  
                if (i \== 0\)  
                {  
                    dp\[i\]\[j\] \= j;  
                }  
                // If second string is empty, remove all characters of first string  
                else if (j \== 0\)  
                {  
                    dp\[i\]\[j\] \= i;  
                }  
                // If last characters are the same, ignore last char and recur for remaining string  
                else if (str1\[i \- 1\] \== str2\[j \- 1\])  
                {  
                    dp\[i\]\[j\] \= dp\[i \- 1\]\[j \- 1\];  
                }  
                // If last character is different, consider all possibilities and find the minimum  
                else  
                {  
                    dp\[i\]\[j\] \= 1 \+ std::min({  
                                       dp\[i \- 1\]\[j\],    // Remove  
                                       dp\[i\]\[j \- 1\],    // Insert  
                                       dp\[i \- 1\]\[j \- 1\] // Replace  
                                   });  
                }  
            }  
        }  
        return dp\[m\]\[k\];  
    }  
};

\`\`\`

\#\#\# Code (Java)

\`\`\`java  
class Solution {  
    public int editDistance(String str1, String str2) {  
        int m \= str1.length();  
        int n \= str2.length();

        int\[\]\[\] dp \= new int\[m \+ 1\]\[n \+ 1\];

        for (int i \= 0; i \<= m; i++) {  
            for (int j \= 0; j \<= n; j++) {  
                // If str1 is empty, we insert all characters of str2  
                if (i \== 0\) {  
                    dp\[i\]\[j\] \= j;  
                }  
                // If str2 is empty, we remove all characters of str1  
                else if (j \== 0\) {  
                    dp\[i\]\[j\] \= i;  
                }  
                // If last characters are the same, ignore them and recur for remaining strings  
                else if (str1.charAt(i \- 1\) \== str2.charAt(j \- 1)) {  
                    dp\[i\]\[j\] \= dp\[i \- 1\]\[j \- 1\];  
                }  
                // If last characters are different, consider all possibilities and find the  
                // minimum  
                else {  
                    dp\[i\]\[j\] \= 1 \+ Math.min(dp\[i\]\[j \- 1\], // Insert  
                            Math.min(dp\[i \- 1\]\[j\], // Remove  
                                    dp\[i \- 1\]\[j \- 1\])); // Replace  
                }  
            }  
        }

        return dp\[m\]\[n\];  
    }  
}

\`\`\`

\#\#\# Code (Python)

\`\`\`python  
class Solution:  
    def editDistance(self, str1, str2):  
        m \= len(str1)  
        n \= len(str2)  
          
        \# Create a 2D array to store minimum operations  
        dp \= \[\[0\] \* (n \+ 1\) for \_ in range(m \+ 1)\]  
          
        \# Initialize dp array for base cases  
        for i in range(m \+ 1):  
            dp\[i\]\[0\] \= i  \# Operations needed to convert str1\[:i\] to an empty string  
          
        for j in range(n \+ 1):  
            dp\[0\]\[j\] \= j  \# Operations needed to convert an empty string to str2\[:j\]  
          
        \# Fill the dp array  
        for i in range(1, m \+ 1):  
            for j in range(1, n \+ 1):  
                if str1\[i \- 1\] \== str2\[j \- 1\]:  
                    dp\[i\]\[j\] \= dp\[i \- 1\]\[j \- 1\]  \# Characters match, no new operation needed  
                else:  
                    dp\[i\]\[j\] \= 1 \+ min(dp\[i \- 1\]\[j\],     \# Deletion  
                                       dp\[i\]\[j \- 1\],     \# Insertion  
                                       dp\[i \- 1\]\[j \- 1\]) \# Replacement  
          
        return dp\[m\]\[n\]  
    

\`\`\`

\#\# Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: \[Any Questions\](https://www.linkedin.com/in/-rushikeshmane/).  
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing\! ⭐

