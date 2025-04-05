# _16. Two Swaps_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/two-swaps--155623/1)

### **Problem Description**

Given a permutation of some of the first natural numbers in an array `arr[]`, determine if the array can be sorted in exactly two swaps. A swap can involve the same pair of indices twice.

Return `true` if it is possible to sort the array with exactly two swaps, otherwise return `false`.

**Examples:**

**Input:**

`arr = [4, 3, 2, 1]`

**Output:**

`true`

**Explanation:**

- First, swap `arr[0]` and `arr[3]`. The array becomes `[1, 3, 2, 4]`.
- Then, swap `arr[1]` and `arr[2]`. The array becomes `[1, 2, 3, 4]`, which is sorted.

**Constraints:**

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ arr.size()`

### **My Approach**

1. **Tracking Mismatches:**
   - The key observation is that sorting a permutation in exactly two swaps means there must be at most two pairs of elements that are out of place.
2. **Checking Sorted Order:**

   - Iterate through the array and check whether the elements are in the correct position. If any element is not in its correct position, count it as a mismatch.

3. **Performing Swaps:**

   - For each mismatch, attempt to swap the misplaced element with its correct position in the array. Keep a count of the swaps made.

4. **Final Check:**
   - If the total number of swaps is exactly 2 or 0, return `true` (the array can be sorted with two swaps). Otherwise, return `false`.

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(n)`, where `n` is the size of the array, as we perform a linear scan of the array and execute swaps in constant time.
- **Expected Auxiliary Space Complexity:** `O(1)`, since we only use a constant amount of additional space for counters and temporary variables.

---

### **Code (C++)**

```cpp
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int n = arr.size();
        int swapCnt = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] == i + 1) continue;
            while(arr[i] != i + 1) {
                swap(arr[arr[i] - 1], arr[i]);
                swapCnt++;
            }
        }
        return (swapCnt == 2 || swapCnt == 0);
    }
};
```

---

### **Code (Java)**

```java
class Solution {
    public boolean checkSorted(List<Integer> arr) {
        int n = arr.size();
        int swapCnt = 0;

        for (int i = 0; i < n; i++) {
            if (arr.get(i) == i + 1) continue;
            while (arr.get(i) != i + 1) {
                Collections.swap(arr, arr.get(i) - 1, i);
                swapCnt++;
            }
        }
        return (swapCnt == 2 || swapCnt == 0);
    }
}
```

---

### **Code (Python)**

```python
class Solution:
    def checkSorted(self, arr):
        n = len(arr)
        swapCnt = 0

        for i in range(n):
            if arr[i] == i + 1:
                continue
            while arr[i] != i + 1:
                arr[arr[i] - 1], arr[i] = arr[i], arr[arr[i] - 1]
                swapCnt += 1

        return swapCnt == 2 or swapCnt == 0
```

---

## **Contribution and Support**

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
