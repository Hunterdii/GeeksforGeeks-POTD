## 14. Segregate 0s and 1s

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1)

### Problem Description

Given an array `arr` consisting of only 0's and 1's in random order, modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

**Examples:**

Input:

```
arr[] = [0, 0, 1, 1, 0]
```

Output:

```
[0, 0, 0, 1, 1]
```

Explanation:
After segregation, all the 0's are on the left and 1's are on the right. The modified array will be [0, 0, 0, 1, 1].

### My Approach

1. **Initialization:**

   - Create two pointers, `left` and `right`, both initialized to 0.
   - `left` will track the position to place the next 0, and `right` will traverse the array.

2. **Segregation Process:**

   - Traverse the array using the `right` pointer.
   - If `arr[right]` is 0, swap it with `arr[left]` and increment `left`.
   - Always increment `right` to continue traversing the array.

3. **Return:**
   - The array `arr` is modified in place with all 0s on the left and 1s on the right.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the array once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the pointers.

### Code (C++)

```cpp
class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = 0;

        while (right < n) {
            if (arr[right] == 0) {
                swap(arr[left], arr[right]);
                left++;
            }
            right++;
        }
    }
};
```

### Code (Java)

```java
class Solution {
    void segregate0and1(int[] arr) {
        int left = 0, right = 0;
        int n = arr.length;

        while (right < n) {
            if (arr[right] == 0) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
            }
            right++;
        }
    }
}
```

### Code (Python)

```python
class Solution:
    def segregate0and1(self, arr):
        left, right = 0, 0
        n = len(arr)

        while right < n:
            if arr[right] == 0:
                arr[left], arr[right] = arr[right], arr[left]
                left += 1
            right += 1
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
