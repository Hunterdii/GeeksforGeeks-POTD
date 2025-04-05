## 21. Three-Way Partitioning

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/three-way-partitioning/1)

### Problem Description

Given an array of size \(n\) and a range \([a, b]\), partition the array around the range such that the array is divided into three parts:

1. All elements smaller than \(a\) come first.
2. All elements in the range \(a\) to \(b\) come next.
3. All elements greater than \(b\) appear in the end.

Note: The individual elements of the three sets can appear in any order. Return 1 if you modify the given array successfully.

**Example:**

Input:

```
n = 5
array[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
```

Output:

```
1
```

Explanation:
One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, the output will be 1.

### My Approach

1. **Initialization:**

   - Initialize two pointers, `left` and `right`, pointing to the start and end of the array respectively.

2. **Partitioning:**

   - Iterate through the array using a loop variable `i`.
   - If `array[i]` is less than \(a\), swap `array[i]` with `array[left]` and increment both `left` and `i`.
   - If `array[i]` is greater than \(b\), swap `array[i]` with `array[right]` and decrement `right`.
   - Otherwise, increment `i`.

3. **Return:**
   - Return 1 if the array is successfully partitioned according to the given conditions.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array once.
- **Expected Auxiliary Space Complexity:** O(1), as we use only a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    void threeWayPartition(vector<int>& array, int a, int b) {
        int n = array.size();
        int left = 0, right = n - 1;

        for (int i = 0; i <= right;) {
            if (array[i] < a) {
                swap(array[i], array[left]);
                left++;
                i++;
            } else if (array[i] > b) {
                swap(array[i], array[right]);
                right--;
            } else {
                i++;
            }
        }
    }
};
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
