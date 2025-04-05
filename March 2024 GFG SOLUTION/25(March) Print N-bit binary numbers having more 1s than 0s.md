## 25. Print N-bit binary numbers having more 1s than 0s

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1)

### Problem Description

Given a positive integer \( n \), generate a list of all \( n \)-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.

**Example:**

Input:

```
n = 2
```

Output:

```
"11, 10"
```

Explanation:
Valid numbers are those where each prefix has more 1s than 0s:

- 11: all its prefixes (1 and 11) have more 1s than 0s.
- 10: all its prefixes (1 and 10) have more 1s than 0s.
  So, the output is "11, 10".

### My Approach

1. **Initialization:**

   - Initialize an empty vector `result` to store the generated binary numbers.

2. **Backtracking:**
   - Implement a recursive function `util` to generate all \( n \)-bit binary numbers satisfying the condition mentioned in the problem.
   - The function takes four parameters: the current output string `out`, the count of ones `on`, the count of zeros `ze`, and the remaining number of bits `n`.
   - If `n` becomes 0, push the current output string to the `result`.
   - If `on` equals `ze`, then it's mandatory to append '1' to the output string and recursively call `util` with `on + 1`, `ze`, and `n - 1`.
   - If `on` is greater than `ze`, then we have two choices: either append '1' or '0' to the output string.
3. **Return:**
   - Return the vector `result` containing the \( n \)-bit binary numbers.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(2^n) \), as we generate all possible \( n \)-bit binary numbers.
- **Expected Auxiliary Space Complexity:** \( O(2^n) \), as we use recursion to generate the binary numbers, and the space required for storing the output vector.

### Code (C++)

```cpp
class Solution{
public:
    vector<string> NBitBinary(int n)
    {
        vector<string> result;
        string out = "";
        int on = 0, ze = 0;

        function<void(string,int,int,int)> util = [&](string out, int on, int ze, int n) {
            if (n == 0) {
                result.push_back(out);
                return;
            }
            if (on == ze) {
                util(out + "1", on + 1, ze, n - 1);
            }
            if (on > ze) {
                util(out + "1", on + 1, ze, n - 1);
                util(out + "0", on, ze + 1, n - 1);
            }
        };

        util(out, on, ze, n);
        return result;
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
