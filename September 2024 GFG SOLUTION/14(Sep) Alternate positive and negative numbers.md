# **14. Alternate Positive and Negative Numbers**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1)

### Problem Description

Given an unsorted array `arr` containing both positive and negative numbers, your task is to create an array of alternating positive and negative numbers without changing the relative order of the positive and negative numbers.

**Note:** The array should start with a positive number, and `0` is considered a positive element.

### Example 1:

Input:

```
arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
```

Output:

```
9 -2 4 -1 5 -5 0 -3 2
```

Explanation:

- Positive elements: `[9, 4, 5, 0, 2]`
- Negative elements: `[-2, -1, -5, -3]`

Alternate placement maintains their relative order.

### Example 2:

Input:

```
arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
```

Output:

```
5 -5 2 -2 4 -8 7 1 8 0
```

Explanation:

- Positive elements: `[5, 2, 4, 7, 1, 8, 0]`
- Negative elements: `[-5, -2, -8]`

### Constraints:

- `1 ≤ arr.size() ≤ 10^7`
- `-10^6 ≤ arr[i] ≤ 10^7`

### My Approach

1. **Separate Positive and Negative Numbers:**

   - Traverse through the input array and separate positive and negative numbers into two different lists, `pos` and `neg`.

2. **Rearrange in Alternating Fashion:**

   - Use a toggle mechanism to alternately place positive and negative numbers from their respective lists back into the original array.
   - If one of the lists is exhausted, append the remaining elements from the other list.

3. **Edge Cases:**
   - If all numbers are positive or all are negative, no rearrangement is needed.
   - Ensure that `0` is treated as a positive number.

### Code (C++)

```cpp
class Solution {
public:
    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            } else {
                neg.push_back(arr[i]);
            }
        }
        int i = 0, j = 0, k = 0;
        bool toggle = true;
        while (i < pos.size() && j < neg.size()) {
            if (toggle) {
                arr[k++] = pos[i++];
            } else {
                arr[k++] = neg[j++];
            }
            toggle = !toggle;
        }
        while (i < pos.size()) {
            arr[k++] = pos[i++];
        }
        while (j < neg.size()) {
            arr[k++] = neg[j++];
        }
    }
};
```

### Code (Java)

```java
class Solution {
    void rearrange(ArrayList<Integer> arr) {
        int n = arr.size();
        ArrayList<Integer> pos = new ArrayList<>();
        ArrayList<Integer> neg = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (arr.get(i) >= 0) {
                pos.add(arr.get(i));
            } else {
                neg.add(arr.get(i));
            }
        }
        int i = 0, j = 0, k = 0;
        boolean toggle = true;
        while (i < pos.size() && j < neg.size()) {
            if (toggle) {
                arr.set(k++, pos.get(i++));
            } else {
                arr.set(k++, neg.get(j++));
            }
            toggle = !toggle;
        }
        while (i < pos.size()) {
            arr.set(k++, pos.get(i++));
        }
        while (j < neg.size()) {
            arr.set(k++, neg.get(j++));
        }
    }
}
```

### Code (Python)

```python
class Solution:
    def rearrange(self, arr):
        n = len(arr)
        pos = []
        neg = []
        for i in range(n):
            if arr[i] >= 0:
                pos.append(arr[i])
            else:
                neg.append(arr[i])
        i = j = k = 0
        toggle = True
        while i < len(pos) and j < len(neg):
            if toggle:
                arr[k] = pos[i]
                i += 1
            else:
                arr[k] = neg[j]
                j += 1
            k += 1
            toggle = not toggle
        while i < len(pos):
            arr[k] = pos[i]
            i += 1
            k += 1
        while j < len(neg):
            arr[k] = neg[j]
            j += 1
            k += 1
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the array twice: once to split positive and negative numbers, and once to rearrange them.
- **Expected Auxiliary Space Complexity:** O(n), as we use two additional lists to store the positive and negative numbers.

---

For any questions or discussions related to this solution, please visit my LinkedIn profile: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for contributing to the community of learners and problem solvers.

⭐ **Star this repository** if you found the solution helpful! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>

---
