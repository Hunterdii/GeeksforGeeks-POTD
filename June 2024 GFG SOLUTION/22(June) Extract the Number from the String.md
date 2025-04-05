## 22. Extract the Number from the String

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1)

### Problem Description

Given a sentence containing several words and numbers, find the largest number among them which does not contain the digit '9'. If no such number exists, return -1.

**Examples:**

Input:

```
sentence = "This is alpha 5057 and 97"
```

Output:

```
5057
```

Explanation:
5057 is the only number that does not contain a 9.

### My Approach

1. **Initialization:**

   - Initialize `num` to -1 to keep track of the largest valid number.
   - Initialize `currentNum` to 0 for constructing numbers from the string.
   - Use boolean flags `validNum` and `hasDigit` to track if the current number is valid and if there are digits being processed.

2. **Parsing the String:**

   - Iterate through each character in the sentence.
   - If the character is a digit:
     - Set `hasDigit` to true.
     - Check if the digit is greater than 8; if so, mark `validNum` as false.
     - Accumulate the digit to `currentNum`.
   - If the character is not a digit:
     - If a number has been constructed (`hasDigit` is true) and it is valid (`validNum` is true) and greater than the current largest number (`num`), update `num`.
     - Reset `currentNum`, `validNum`, and `hasDigit` for the next potential number.

3. **Final Check:**

   - After the loop, perform a final check to consider the last constructed number.

4. **Return:**
   - Return the largest valid number found, or -1 if no valid number exists.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where \(n\) is the length of the sentence, as we iterate through each character of the string.
- **Expected Auxiliary Space Complexity:** O(n), as we only use a constant amount of additional space for variables.

### Code (C++)

```cpp
class Solution {
public:
    long long ExtractNumber(string sentence) {
        long long num = -1;
        long long currentNum = 0;
        bool validNum = true;
        bool hasDigit = false;

        for (char c : sentence) {
            if (isdigit(c)) {
                hasDigit = true;
                if (c - '0' > 8) {
                    validNum = false;
                }
                currentNum = currentNum * 10 + (c - '0');
            } else {
                if (hasDigit && validNum && currentNum > num) {
                    num = currentNum;
                }
                currentNum = 0;
                validNum = true;
                hasDigit = false;
            }
        }
        if (hasDigit && validNum && currentNum > num) {
            num = currentNum;
        }

        return num;
    }
};
```

### Code (Java)

```java
class Solution {
    long ExtractNumber(String sentence) {
        long num = -1;
        long currentNum = 0;
        boolean validNum = true;
        boolean hasDigit = false;

        for (char c : sentence.toCharArray()) {
            if (Character.isDigit(c)) {
                hasDigit = true;
                if (c - '0' > 8) {
                    validNum = false;
                }
                currentNum = currentNum * 10 + (c - '0');
            } else {
                if (hasDigit && validNum && currentNum > num) {
                    num = currentNum;
                }
                currentNum = 0;
                validNum = true;
                hasDigit = false;
            }
        }

        if (hasDigit && validNum && currentNum > num) {
            num = currentNum;
        }

        return num;
    }
}
```

### Code (Python)

```python
import re

class Solution:
    def ExtractNumber(self, sentence):
        numbers = re.findall(r'\d+', sentence)

        answer = -1
        max_value = -1

        for number in numbers:
            num_value = int(number)
            if '9' not in number and num_value > max_value:
                answer = number
                max_value = num_value

        return answer
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
