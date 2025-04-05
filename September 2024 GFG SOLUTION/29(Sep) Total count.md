# _29. Total Count_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/total-count2415/1)

### Problem Description

You are given an array `arr[]` of positive integers and a threshold value `k`. For each element in the array, divide it into the minimum number of small integers such that each divided integer is less than or equal to `k`. Compute the total number of these integers across all elements of the array.

_Example 1:_

Input:

```
k = 3, arr[] = [5, 8, 10, 13]
```

Output:

```
14
```

Explanation: Each number can be expressed as a sum of smaller numbers less than or equal to `k`:

- 5 → (3 + 2),
- 8 → (3 + 3 + 2),
- 10 → (3 + 3 + 3 + 1),
- 13 → (3 + 3 + 3 + 3 + 1).

The total count is 2 + 3 + 4 + 5 = 14.

### My Approach

1. **Iterate Over Each Element**:
   - For each element in `arr`, divide it into groups of size `k` or smaller.
   - Add the count of groups for each element to the total count.
2. **Mathematical Breakdown**:

   - For any number `num` in `arr`, the total number of groups required is given by:
     ```
     (num + k - 1) // k
     ```
     This expression divides `num` into chunks of size `k`, accounting for any remainder.

3. **Final Answer**:
   - Sum up the counts for all elements in the array to get the total count.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:**  
  `O(n)`, where `n` is the size of the input array `arr[]`, since we iterate over each element of the array once.
- **Expected Auxiliary Space Complexity:**  
  `O(1)`, as we use only a constant amount of extra space regardless of the input size.

### Code (C++)

```cpp
class Solution {
public:
    int totalCount(int k, vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            count += (num + k - 1) / k;
        }
        return count;
    }
};
```

### Code (Java)

```java
class Solution {
    int totalCount(int k, int[] arr) {
        int count = 0;
        for (int num : arr) {
            count += (num + k - 1) / k;
        }
        return count;
    }
}
```

### Code (Python)

```python
class Solution:
    def totalCount(self, k, arr):
        count = 0
        for num in arr:
            count += (num + k - 1) // k
        return count
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
