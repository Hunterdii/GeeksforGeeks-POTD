## 18. Two Repeated Elements

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1)

### Problem Description

Given an integer \( n \) and an integer array \( \text{arr} \) of size \( n+2 \), where all elements of the array are in the range from 1 to \( n \), except for two numbers which occur twice. Find the two repeating numbers.

**Example:**

Input:

```
n = 4
arr[] = {1,2,1,3,4,3}
```

Output:

```
1 3
```

Explanation:
In the given array, 1 and 3 are repeated two times, and as 1's second appearance occurs before 2's second appearance, so the output should be 1 3.

### My Approach

1. **Initialization:**

   - Create an unordered set `seen` to keep track of numbers we have seen.
   - Create an empty vector `result` to store the repeating numbers.

2. **Iteration:**
   - Iterate through the array `arr[]` from index 0 to \( N + 1 \).
3. **Identify Repeated Elements:**

   - If the current element is already in the set `seen`, it is a repeating number. Add it to the `result` vector.
   - Otherwise, add the current element to the set `seen`.

4. **Return Result:**
   - Return the `result` vector containing the two repeating numbers.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array once.
- **Expected Auxiliary Space Complexity:** O(n), as we use an unordered set to store unique elements.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> twoRepeated(int arr[], int N) {
        unordered_set<int> seen;
        vector<int> result;

        for (int i = 0; i < N + 2; ++i) {
            if (seen.count(arr[i])) {
                result.push_back(arr[i]);
            } else {
                seen.insert(arr[i]);
            }
        }

        return result;
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
