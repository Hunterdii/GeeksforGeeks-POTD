## 10. Remove Duplicate Characters

The problem statement can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1)

### Approach Explanation

1. **Initialization:**
   - Initialize an empty unordered set `seen` to store characters that have been encountered.
   - Initialize an empty string `result` to store the final output.

2. **Iteration Process:**
   - Iterate through each character `c` in the input string `str`.

3. **Check for Duplicates:**
   - For each character `c`, check if it has been seen before. If not, append it to the `result` string and add it to the `seen` set.

4. **Finalization:**
   - After iterating through all characters in the input string, return the `result` string containing unique characters only.

This approach effectively removes duplicate characters from the input string while maintaining the original order of characters.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(N), where N is the length of the input string.
- **Auxiliary Space Complexity**: O(N), where N is the length of the input string, for storing unique characters in the unordered set.

### Code (C++)
```cpp
class Solution {
public:
    std::string removeDuplicates(std::string str) {
        std::unordered_set<char> seen;
        std::string result = "";
        
        for (char& c : str) {
            if (seen.find(c) == seen.end()) {
                result += c;
                seen.insert(c);
            }
        }
        
        return result;
    }
};

```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/).
Thank you for your input, together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
