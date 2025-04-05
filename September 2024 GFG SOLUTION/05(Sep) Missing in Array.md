# **5. Missing in Array**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given an array `arr` of size `n−1` containing distinct integers in the range of 1 to `n` (inclusive), find the missing element. The array is a permutation of size `n` with one element missing. Return the missing element.

**Examples:**

Input:

```
n = 5, arr[] = [1,2,3,5]
```

Output:

```
4
```

Explanation: All numbers from 1 to 5 are present except 4.

### My Approach

1. **XOR Property:**

   - The XOR of a number with itself is 0.
   - The XOR of a number with 0 is the number itself.

2. **Solution Outline:**
   - Compute the XOR of all integers from 1 to `n` and store it in `xorTotal`.
   - Compute the XOR of all elements in the array `arr` and store it in `xorArray`.
   - The missing number will be the XOR of `xorTotal` and `xorArray`, as the duplicate numbers will cancel out due to the XOR property.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate over the entire array and the range from 1 to `n`.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store the XOR results.

### Code (C)

```c
int missingNumber(int n, int arr[]) {
    int xorTotal = 0;
    int xorArray = 0;
    for (int i = 1; i <= n; i++)
        xorTotal ^= i;
    for (int i = 0; i < n - 1; i++)
        xorArray ^= arr[i];
    return xorTotal ^ xorArray;
}
```

### Code (C++)

```cpp
class Solution {
public:
    int missingNumber(int n, vector<int>& arr) {
        int xorTotal = 0;
        for (int i = 1; i <= n; i++) {
            xorTotal ^= i;
        }
        int xorArray = 0;
        for (int i = 0; i < n - 1; i++) {
            xorArray ^= arr[i];
        }
        return xorTotal ^ xorArray;
    }
};
```

### Code (Java)

```java
class Solution {
    int missingNumber(int n, int arr[]) {
        int xorTotal = 0;
        for (int i = 1; i <= n; i++) {
            xorTotal ^= i;
        }
        int xorArray = 0;
        for (int i = 0; i < n - 1; i++) {
            xorArray ^= arr[i];
        }
        return xorTotal ^ xorArray;
    }
}
```

### Code (Python)

```python
class Solution:
    def missingNumber(self, n, arr):
        xor_total = 0
        for i in range(1, n + 1):
            xor_total ^= i
        xor_array = 0
        for num in arr:
            xor_array ^= num
        return xor_total ^ xor_array
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
