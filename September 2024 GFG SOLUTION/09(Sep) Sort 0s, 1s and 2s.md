# **09. Sort 0s, 1s, and 2s**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given an array `arr` containing only `0`s, `1`s, and `2`s, sort the array in ascending order.

**Example:**

Input:

```
arr = [0, 2, 1, 2, 0]
```

Output:

```
0 0 1 2 2
```

Explanation: `0`s, `1`s, and `2`s are segregated into ascending order.

Input:

```
arr = [0, 1, 0]
```

Output:

```
0 0 1
```

Explanation: `0`s, `1`s, and `2`s are segregated into ascending order.

### My Approach

1. **Three-Pointer Approach:**

   - Use three pointers `low`, `mid`, and `high` to partition the array into three segments: 0s, 1s, and 2s.

2. **Initialization:**

   - `low` and `mid` pointers start at the beginning of the array, while the `high` pointer starts at the end of the array.

3. **Partitioning:**

   - Iterate through the array using the `mid` pointer:
     - If `arr[mid]` is `0`, swap `arr[mid]` with `arr[low]`, increment both `low` and `mid`.
     - If `arr[mid]` is `1`, simply move the `mid` pointer forward.
     - If `arr[mid]` is `2`, swap `arr[mid]` with `arr[high]` and decrement `high`.

4. **Final Array:**
   - After the loop, the array will be sorted in ascending order with all `0`s, `1`s, and `2`s in their respective positions.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the array. Each element is processed at most once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointers.

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

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>

---
