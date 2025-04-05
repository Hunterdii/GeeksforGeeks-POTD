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
    string longestSubstring(string S, int N) {
        // code here
        int maxLen = 0;
        string ans = "-1";
        int i = 0, j = 0;

        while (i < N && j < N) {
            string subString = S.substr(i, j - i + 1);

            if (S.find(subString, j + 1) != string::npos) {
                int len = subString.length();
                if (len > maxLen) {
                    maxLen = len;
                    ans = subString;
                }
            } else {
                i++;
            }
            j++;
        }
        return ans;
    }
};
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
