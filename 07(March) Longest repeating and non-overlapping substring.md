## 07. Longest repeating and non-overlapping substring
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1)

### My Approach

1. **Initialization**: Start by setting up some variables to keep track of the longest repeating substring (`out`), its length (`nax`), and two pointers (`i` and `j`).

2. **Sliding Window**: Move through the string `s` using two pointers (`i` and `j`). These pointers define a window that slides through the string.

3. **Substring Checking**: At each window position, we check if the substring within the window appears later in the string. If it does, and it's longer than the previously found longest repeating substring (`out`), we update `out` and `nax`.

4. **Updating Pointers**: Slide the window by adjusting the pointers (`i` and `j`) based on certain conditions.

5. **Return**: Finally, return the longest repeating and non-overlapping substring found.

This approach essentially scans through the string, considering all possible substrings, and updates the longest repeating substring whenever it finds a longer one that repeats later in the string. By sliding the window, it efficiently explores all possibilities.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^2)`, where n is the length of the input string. This complexity arises from generating all possible substrings and checking for repeats.
- **Auxiliary Space Complexity**: `O(1)`, as we are not using any extra space that grows with the input size.

### Code (C++)

```cpp
class Solution {
public:
    string longestSubstring(string s, int n) {
        int nax = 0, i = 0, j = 0;
        string out = "-1";
    
        for( ; i < n && j < n; ++j) {
            string str = s.substr(i, j - i + 1);
    
            if (nax < str.size() && s.find(str, j + 1) != string::npos) {
                nax = str.size();
                out = str;
            } else 
                ++i;
        }
        return out;
    }
};
```

### Contribution and Support


For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). 
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
