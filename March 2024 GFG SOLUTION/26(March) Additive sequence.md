## 26. Additive Sequence

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/additive-sequence/1)

### Problem Description

Given a string `n`, your task is to find whether it contains an additive sequence or not. A string `n` contains an additive sequence if its digits can make a sequence of numbers in which every number is the addition of the previous two numbers. You are required to complete the function which returns true if the string is a valid sequence, else returns false. For better understanding, check the examples.

Note: A valid string should contain at least three digits to make one additive sequence.

**Example:**

Input:

```
n = "1235813"
```

Output:

```
1
```

Explanation:
The given string can be split into a series of numbers where each number is the sum of the previous two numbers:
1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8, and 5 + 8 = 13. Hence, the output would be 1 (true).

### My Approach

1. **Validation:**

   - Start by validating if the given string `n` contains at least three digits. If not, return false.

2. **Iteration:**

   - Iterate over all possible combinations of two numbers that can form the additive sequence.
   - Calculate the sum of the first two numbers and check if it matches the next number in the sequence.
   - If it matches, continue the sequence by considering the next number.

3. **Validation Check:**

   - If the sequence can continue till the end of the string without any discrepancies, return true.

4. **Return False:**
   - If no valid additive sequence is found, return false.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^3), as there are three nested loops iterating over the string.
- **Expected Auxiliary Space Complexity:** O(1), as we use only a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    bool isAdditiveSequence(const string& s) {
        int n = s.size();
        if (n < 3) return false;

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string num1 = s.substr(0, i);
                string num2 = s.substr(i, j - i);
                if (isValid(s.substr(j), num1, num2))
                    return true;
            }
        }
        return false;
    }

private:
    bool isValid(const string& s, const string& num1, const string& num2) {
        if (s.empty()) return true;
        string sum = add(num1, num2);
        if (s.find(sum) == 0)
            return isValid(s.substr(sum.size()), num2, sum);
        return false;
    }

    string add(const string& num1, const string& num2) {
        string result;
        int carry = 0;
        int i = num1.length() - 1, j = num2.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
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
