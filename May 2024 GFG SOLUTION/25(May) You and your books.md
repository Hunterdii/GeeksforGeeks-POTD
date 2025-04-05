## 25. You and your books

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/you-and-your-books/1)

### Problem Description

You have `n` stacks of books. Each stack of books has some nonzero height `arr[i]` equal to the number of books in that stack (considering all books are identical and each book has a height of 1 unit). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books `arr[i] <= k`. Once such a sequence of stacks is chosen, you can collect any number of books from the chosen sequence of stacks.

What is the maximum number of books that you can collect this way?

**Example:**

Input:

```
8 1
3 2 2 3 1 1 1 3
```

Output:

```
3
```

Explanation:
We can collect the maximum books from consecutive stacks numbered 5, 6, and 7 having a height less than or equal to `k`.

### My Approach

1. **Initialization:**

   - Initialize two variables: `max_sum` to keep track of the maximum number of books that can be collected, and `current_sum` to store the number of books in the current valid sequence.

2. **Iterate Through the Array:**

   - Iterate through each stack of books in the array `arr`.
   - If the height of the current stack `arr[i]` is less than or equal to `k`, add the height of the current stack to `current_sum` and update `max_sum` if `current_sum` is greater than `max_sum`.
   - If the height of the current stack is greater than `k`, reset `current_sum` to 0, as the current stack cannot be included in a valid sequence.

3. **Return:**
   - Return `max_sum`, which contains the maximum number of books that can be collected from the valid sequences.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array of stacks only once.
- **Expected Auxiliary Space Complexity:** O(1), as we use only a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    long long max_Books(int a[], int n, int k) {
        long long max_sum = 0, current_sum = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] <= k) {
                current_sum += a[i];
                max_sum = std::max(max_sum, current_sum);
            } else {
                current_sum = 0;
            }
        }
        return max_sum;
    }
};
```

### Code (Java)

```java
class Solution {
    long max_Books(int arr[], int n, int k) {
        long max_sum = 0, current_sum = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                current_sum += arr[i];
                max_sum = Math.max(max_sum, current_sum);
            } else {
                current_sum = 0;
            }
        }
        return max_sum;
    }
}
```

### Code (Python)

```python
class Solution:
    # Function to find the maximum number of books
    def max_Books(self, n, k, arr):
        max_sum = 0
        current_sum = 0

        for i in range(n):
            if arr[i] <= k:
                current_sum += arr[i]
                max_sum = max(max_sum, current_sum)
            else:
                current_sum = 0

        return max_sum
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
