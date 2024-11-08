# **01. Max Sum Path in Two Arrays**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given two sorted arrays of distinct integers, `arr1` and `arr2`, each containing some common elements, find the maximum sum of a path from the beginning of any array to the end of any array. You can switch from one array to the other only at the common elements. The common element should be considered only once in the result when switching.

**Examples:**

Input:
```
arr1 = [2, 3, 7, 10, 12]
arr2 = [1, 5, 7, 8]
```
Output:
```
35
```
Explanation: The path will be `1+5+7+10+12 = 35`, where `1` and `5` come from `arr2`, and then `7` is common, so we switch to `arr1` and add `10` and `12`.


### My Approach

1. **Initialization:**
   - Start by initializing two pointers, `i` and `j`, to traverse `arr1` and `arr2` respectively.
   - Maintain two sums, `sum1` and `sum2`, to store the path sums for the current segments of `arr1` and `arr2`.

2. **Traverse Both Arrays:**
   - As you traverse both arrays, accumulate the values into `sum1` and `sum2`.
   - When a common element is encountered, compare `sum1` and `sum2`, add the maximum to the result, and reset the sums.

3. **Post-Traversal:**
   - After the common elements are exhausted, add the remaining elements of the longer array to the result.

4. **Final Result:**
   - The result will be the maximum sum path possible from the start of one array to the end of the other.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(m + n), where `m` is the length of `arr1` and `n` is the length of `arr2`, since each element is visited once.
- **Expected Auxiliary Space Complexity:** O(1), as the space required is constant regardless of the size of the input arrays.

### Code (C++)

```cpp
class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int i = 0, j = 0;
        int result = 0, sum1 = 0, sum2 = 0;
        int m = arr1.size(), n = arr2.size();
        
        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                sum1 += arr1[i++];
            } else if (arr1[i] > arr2[j]) {
                sum2 += arr2[j++];
            } else {
                result += max(sum1, sum2) + arr1[i];  
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }
        while (i < m) sum1 += arr1[i++];
        while (j < n) sum2 += arr2[j++];
        
        result += max(sum1, sum2);

        return result;
    }
};
```

### Code (Java)

```java
class Solution {
    public int maxPathSum(List<Integer> arr1, List<Integer> arr2) {
        int i = 0, j = 0;
        int result = 0, sum1 = 0, sum2 = 0;
        int m = arr1.size(), n = arr2.size();
        
        while (i < m && j < n) {
            if (arr1.get(i) < arr2.get(j)) {
                sum1 += arr1.get(i++);
            } else if (arr1.get(i) > arr2.get(j)) {
                sum2 += arr2.get(j++);
            } else {
                result += Math.max(sum1, sum2) + arr1.get(i);
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }
        while (i < m) sum1 += arr1.get(i++);
        while (j < n) sum2 += arr2.get(j++);
        
        result += Math.max(sum1, sum2);

        return result;
    }
}
```

### Code (Python)

```python
class Solution:
    def maxPathSum(self, arr1, arr2):
        i, j = 0, 0
        result, sum1, sum2 = 0, 0, 0
        m, n = len(arr1), len(arr2)
        
        while i < m and j < n:
            if arr1[i] < arr2[j]:
                sum1 += arr1[i]
                i += 1
            elif arr1[i] > arr2[j]:
                sum2 += arr2[j]
                j += 1
            else:
                result += max(sum1, sum2) + arr1[i]
                sum1 = sum2 = 0
                i += 1
                j += 1

        while i < m:
            sum1 += arr1[i]
            i += 1

        while j < n:
            sum2 += arr2[j]
            j += 1

        result += max(sum1, sum2)

        return result
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---
<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
