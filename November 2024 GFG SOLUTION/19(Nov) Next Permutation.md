# _19. Next Permutation_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/next-permutation5226/1)

<div align="center">
  <h2>🗳️ Cast Your Vote!</h2>
  <p>Help shape the future of this repository! Vote now to decide whether I should start adding LeetCode POTD solutions alongside GeeksforGeeks. Your opinion matters! 🌟</p>
  <a href="https://github.com/Hunterdii/GeeksforGeeks-POTD/discussions/15" style="text-decoration: none;">
    <img src="https://img.shields.io/badge/Vote%20Now%20-%20Your%20Opinion%20Matters-blue?style=for-the-badge&logo=github&logoColor=white" alt="Vote Now Badge">
  </a>
</div>

<br/>

## Problem Description

Given an array of integers `arr[]` representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order).

**Note:** A permutation of `n` numbers is any possible arrangement of all the integers in the range `[1, n]`, where each integer occurs exactly once.

### Examples:

**Input:**  
`arr = [2, 4, 1, 7, 5, 0]`  
**Output:**  
`[2, 4, 5, 0, 1, 7]`

**Explanation:**  
The next permutation of the given array is `[2, 4, 5, 0, 1, 7]`.

**Input:**  
`arr = [3, 2, 1]`  
**Output:**  
`[1, 2, 3]`

**Explanation:**  
As `arr[]` is the last permutation, the next permutation is the lowest one.

**Input:**  
`arr = [3, 4, 2, 5, 1]`  
**Output:**  
`[3, 4, 5, 1, 2]`

**Explanation:**  
The next permutation of the given array is `[3, 4, 5, 1, 2]`.

### Constraints:

- `1 ≤ arr.size() ≤ 10^5`
- `1 ≤ arr[i] ≤ 10^5`

## My Approach

1. **Identify the Pivot:**

   - Start from the rightmost side of the array and find the first index `i` such that `arr[i] < arr[i+1]`.
   - This index `i` is the pivot where the next permutation needs to be modified.

2. **Swap with Successor:**

   - Find the smallest element on the right of `i` that is greater than `arr[i]` and swap them. This ensures the permutation becomes lexicographically larger.

3. **Reverse the Suffix:**
   - Reverse the elements from `i+1` to the end of the array to get the next smallest permutation.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the array multiple times to find the pivot, the successor, and reverse the suffix.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for temporary variables.

## Code (C)

```c
void nextPermutation(int arr[], int n) {
    int i = n - 2, j = n - 1;

    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i >= 0) {
        while (arr[j] <= arr[i])
            j--;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int start = i + 1, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
```

## Code (C++)

```cpp
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size(), i = n - 2, j = n - 1;

        while (i >= 0 && arr[i] >= arr[i + 1])
            i--;

        if (i >= 0) {
            while (arr[j] <= arr[i])
                j--;
            swap(arr[i], arr[j]);
        }

        reverse(arr.begin() + i + 1, arr.end());
    }
};
```

## Code (Java)

```java
class Solution {
    void nextPermutation(int[] arr) {
        int n = arr.length;
        int i = n - 2, j = n - 1;

        while (i >= 0 && arr[i] >= arr[i + 1])
            i--;

        if (i >= 0) {
            while (arr[j] <= arr[i])
                j--;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        reverse(arr, i + 1, n - 1);
    }

    void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}
```

## Code (Python)

```python
class Solution:
    def nextPermutation(self, arr):
        n = len(arr)
        i = n - 2

        while i >= 0 and arr[i] >= arr[i + 1]:
            i -= 1

        if i >= 0:
            j = n - 1

            while arr[j] <= arr[i]:
                j -= 1

            arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1:] = reversed(arr[i + 1:])
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

<details>
  <summary><h2 align='center'>💬 Poll Update</h2></summary> 
  Hey, amazing community! 😄  
  <br/>
  I've been consistently posting GeeksforGeeks POTD solutions, but now I’m thinking of starting LeetCode POTD as well! 🚀  
  <br/>
  
  💡 **What do you think?** Should I start adding LeetCode solutions or wait until next month?  
  <br/>
  
  🗓️ **Poll deadline:** Please cast your vote before **November 20** to help me finalize the decision! Your feedback is crucial.  
  <br/><br/>
  [🔗 Click here to vote now!](https://github.com/Hunterdii/GeeksforGeeks-POTD/discussions/15)  
  <br/>
  If the tie remains, I’ll start adding LeetCode POTD solutions next month. 🙌
</details>

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
