## 18. Longest Alternating Subsequence

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1)

### Problem Description

You are given an array `arr`. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations:

1. \(x1 < x2 > x3 < x4 > x5 ...\)
2. \(x1 > x2 < x3 > x4 < x5 ...\)

**Examples:**

Input:

```
arr = [1, 5, 4]
```

Output:

```
3
```

Explanation:
The entire sequence is a good sequence.

### My Approach

1. **Initialization:**

   - Check if the size of the array `arr` is less than 2. If true, return the size of the array as the longest length.
   - Initialize two variables `up` and `down` to 1, representing the length of the longest alternating subsequence ending with an increasing or decreasing element respectively.

2. **Alternating Subsequence Calculation:**

   - Iterate through the array starting from the second element.
   - For each element, check if it is greater than the previous element. If true, update `up` as `down + 1`.
   - Otherwise, if it is smaller than the previous element, update `down` as `up + 1`.

3. **Return:**
   - Return the maximum value between `up` and `down`, which gives the length of the longest alternating subsequence.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array once.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int alternatingMaxLength(vector<int>& arr) {
        if (arr.size() < 2)
            return arr.size();

        int up = 1, down = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1])
                up = down + 1;
            else if (arr[i] < arr[i - 1])
                down = up + 1;
        }
        return max(up, down);
    }
};
```

### Code (Java)

```java
class Solution {
    public int alternatingMaxLength(int[] arr) {
        if (arr.length < 2)
            return arr.length;

        int up = 1, down = 1;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > arr[i - 1])
                up = down + 1;
            else if (arr[i] < arr[i - 1])
                down = up + 1;
        }

        return Math.max(up, down);
    }
}
```

### Code (Python)

```python
class Solution:
    def alternatingMaxLength(self, arr):
        if len(arr) < 2:
            return len(arr)

        up = 1
        down = 1

        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                up = down + 1
            elif arr[i] < arr[i - 1]:
                down = up + 1

        return max(up, down)
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
