# *09. Minimum Sum*

The problem can be found at the following link: [Problem Link](https://geeksforgeeks.org/problems/minimum-sum4058/1)

## Problem Description

Given an array `arr[]` where each element is a digit in the range `[0 - 9]`, find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers, and the function should return the minimum sum as a string without leading zeroes.

### Examples:

**Input:**  
```
arr[] = [6, 8, 4, 5, 2, 3]
```

**Output:**  
```
604
```

**Explanation:**  
The minimum sum is formed by numbers 358 and 246, giving a sum of 604.

**Input:**  
```
arr[] = [5, 3, 0, 7, 4]
```

**Output:**  
```
82
```

**Explanation:**  
The minimum sum is formed by numbers 35 and 47, giving a sum of 82.

**Input:**  
```
arr[] = [9, 4]
```

**Output:**  
```
13
```

**Explanation:**  
The minimum sum is formed by numbers 9 and 4, giving a sum of 13.

### Constraints:
- 1 ≤ arr.size() ≤ 10^6
- 0 ≤ arr[i] ≤ 9

## My Approach

1. **Sorting and Partitioning**:
   - Sort the array in ascending order to minimize the values formed by the two numbers.
   - Alternate the sorted digits between two numbers, `num1` and `num2`, to keep both as balanced as possible in terms of value.
   - Skip any leading zeros in `num1` or `num2` to avoid unnecessary padding.

2. **Sum Calculation**:
   - Use a helper function to calculate the sum of `num1` and `num2` represented as strings. This avoids overflow issues for large numbers and ensures the result is presented without leading zeros.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** (O(n log n)), as the array needs to be sorted to ensure minimal values for `num1` and `num2`.
- **Expected Auxiliary Space Complexity:** (O(n)), for storing the numbers `num1` and `num2`.

## Code (C++)

```cpp
class Solution {
public:
    string minSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string num1, num2;
        bool toggle = true;
        
        for (int i = 0; i < n; i++) {
            if (toggle) {
                if (!(arr[i] == 0 && num1.empty())) 
                    num1 += to_string(arr[i]);
            } else {
                if (!(arr[i] == 0 && num2.empty())) 
                    num2 += to_string(arr[i]);
            }
            toggle = !toggle;
        }

        if (num1.empty()) num1 = "0";
        if (num2.empty()) num2 = "0";
        return findSum(num1, num2);
    }

private:
    string findSum(const string& str1, const string& str2) {
        int n1 = str1.size(), n2 = str2.size();
        int carry = 0;
        string result;
        
        for (int i = 0; i < max(n1, n2) || carry; i++) {
            int digit1 = i < n1 ? str1[n1 - i - 1] - '0' : 0;
            int digit2 = i < n2 ? str2[n2 - i - 1] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
```

## Code (Java)

```java
class Solution {
    public String minSum(int[] arr) {
        Arrays.sort(arr);
        StringBuilder num1 = new StringBuilder();
        StringBuilder num2 = new StringBuilder();
        boolean toggle = true;

        for (int num : arr) {
            if (toggle) {
                if (!(num == 0 && num1.length() == 0)) {
                    num1.append(num);
                }
            } else {
                if (!(num == 0 && num2.length() == 0)) {
                    num2.append(num);
                }
            }
            toggle = !toggle;
        }

        if (num1.length() == 0) num1.append("0");
        if (num2.length() == 0) num2.append("0");

        return findSum(num1.toString(), num2.toString());
    }

    private String findSum(String str1, String str2) {
        int n1 = str1.length(), n2 = str2.length();
        int carry = 0;
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < Math.max(n1, n2) || carry > 0; i++) {
            int digit1 = i < n1 ? str1.charAt(n1 - i - 1) - '0' : 0;
            int digit2 = i < n2 ? str2.charAt(n2 - i - 1) - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.append(sum % 10);
            carry = sum / 10;
        }

        return result.reverse().toString();
    }
}
```

## Code (Python)

```python
class Solution:
    def minSum(self, arr):
        arr.sort()
        num1, num2 = "", ""
        toggle = True

        for num in arr:
            if toggle:
                if not (num == 0 and not num1):
                    num1 += str(num)
            else:
                if not (num == 0 and not num2):
                    num2 += str(num)
            toggle = not toggle

        if not num1:
            num1 = "0"
        if not num2:
            num2 = "0"

        return self.findSum(num1, num2)

    def findSum(self, str1, str2):
        n1, n2 = len(str1), len(str2)
        carry = 0
        result = []

        for i in range(max(n1, n2)):
            digit1 = int(str1[n1 - i - 1]) if i < n1 else 0
            digit2 = int(str2[n2 - i - 1]) if i < n2 else 0
            total = digit1 + digit2 + carry
            result.append(str(total % 10))
            carry = total // 10

        if carry:
            result.append(str(carry))

        return ''.join(result[::-1])
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
