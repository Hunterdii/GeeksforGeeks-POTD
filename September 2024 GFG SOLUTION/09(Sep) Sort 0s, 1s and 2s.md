# **9. Minimum Number of Jumps to Reach End**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given an array of integers `arr[]` where each element represents the maximum number of steps that can be jumped going forward from that element, find the minimum number of jumps to reach the end of the array (starting from the first element). If it is not possible to reach the end, return `-1`.

**Example:**

Input:
```
arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
```
Output:
```
3
```
Explanation: The minimum number of jumps to reach the end is `3` (1 -> 3 -> 8 -> 9).

### My Approach

1. **Greedy Approach:**
   - Track the maximum reachable index as we traverse the array.
   - Use two variables, `maxReach` and `steps`, where `maxReach` keeps the maximum index we can reach, and `steps` counts the number of steps taken.
   - At every index, check if `maxReach` needs to be updated based on the current value.
   - When the current number of steps is exhausted, increment the jump counter and check if further progress can be made.

2. **Edge Cases:**
   - If the array has only one element, no jumps are needed.
   - If the first element is `0`, return `-1` because the end cannot be reached.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the input array. We only traverse the array once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of extra space for variables.

### Code (C++)

```cpp
class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;

        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } 
            else if (arr[mid] == 1) {
                mid++;
            } 
            else {  
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
```

### Code (Java)

```java
class Solution {
class Solution {
    public void sort012(ArrayList<Integer> arr) {
        int low = 0, mid = 0, high = arr.size() - 1;

        while (mid <= high) {
            if (arr.get(mid) == 0) {
                Collections.swap(arr, low, mid);
                low++;
                mid++;
            } else if (arr.get(mid) == 1) {
                mid++;
            } else {
                Collections.swap(arr, mid, high);
                high--;
            }
        }
    }
}
```

### Code (Python)

```python
class Solution:
    def sort012(self, arr):
        low, mid, high = 0, 0, len(arr) - 1

        while mid <= high:
            if arr[mid] == 0:
                arr[low], arr[mid] = arr[mid], arr[low]
                low += 1
                mid += 1
            elif arr[mid] == 1:
                mid += 1
            else:
                arr[mid], arr[high] = arr[high], arr[mid]
                high -= 1
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---
<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
