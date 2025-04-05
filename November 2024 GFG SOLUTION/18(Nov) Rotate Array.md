# _18. Rotate Array_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1)

<div align="center">
  <h2>🗳️ Cast Your Vote!</h2>
  <p>Help shape the future of this repository! Vote now to decide whether I should start adding LeetCode POTD solutions alongside GeeksforGeeks. Your opinion matters! 🌟</p>
  <a href="https://github.com/Hunterdii/GeeksforGeeks-POTD/discussions/15" style="text-decoration: none;">
    <img src="https://img.shields.io/badge/Vote%20Now%20-%20Your%20Opinion%20Matters-blue?style=for-the-badge&logo=github&logoColor=white" alt="Vote Now Badge">
  </a>
</div>

<br/>

> **Note:** I'm currently in the middle of my exams until November 19, so I’ll be uploading daily POTD solutions, but not at a fixed time. Apologies for any inconvenience, and thank you for your patience!

## Problem Description

Given an unsorted array `arr[]`. Rotate the array to the left (counter-clockwise direction) by `d` steps, where `d` is a positive integer. Do the mentioned change in the array in place.

**Note:** Consider the array as circular.

### Examples:

**Input:**  
`arr[] = [1, 2, 3, 4, 5]`, `d = 2`  
**Output:**  
`[3, 4, 5, 1, 2]`

**Explanation:**  
When rotated by 2 elements, it becomes `[3, 4, 5, 1, 2]`.

**Input:**  
`arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]`, `d = 3`  
**Output:**  
`[8, 10, 12, 14, 16, 18, 20, 2, 4, 6]`

**Explanation:**  
When rotated by 3 elements, it becomes `[8, 10, 12, 14, 16, 18, 20, 2, 4, 6]`.

**Input:**  
`arr[] = [7, 3, 9, 1]`, `d = 9`  
**Output:**  
`[3, 9, 1, 7]`

**Explanation:**  
When we rotate 9 times, we'll get `[3, 9, 1, 7]` as the resultant array.

### Constraints:

- `1 <= arr.size(), d <= 10^5`
- `0 <= arr[i] <= 10^5`

## My Approach

1. **Rotation Process:**

   - The idea is to rotate the array in three parts by reversing the elements in each part:
     1. Reverse the first `d` elements.
     2. Reverse the remaining elements from index `d` to `n-1`.
     3. Reverse the entire array to get the final rotated array.
   - This way, we achieve the desired result without using extra space.

2. **Steps:**
   - First, we reverse the first `d` elements.
   - Then, reverse the rest of the array (from index `d` to `n-1`).
   - Finally, reverse the entire array.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of elements in the array. We perform constant-time operations like swapping elements, each occurring at most `n` times.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for temporary variables.

## Code (C)

```c
void rotateArr(int arr[], int n, int d) {
    d %= n;

    for (int i = 0; i < d / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[d - i - 1];
        arr[d - i - 1] = temp;
    }

    for (int i = d; i < (n + d) / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - (i - d) - 1];
        arr[n - (i - d) - 1] = temp;
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
```

## Code (Cpp)

```cpp
class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;

        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.begin() + n);
        reverse(arr.begin(), arr.begin() + n);
    }
};
```

## Code (Java)

```java
class Solution {
    static void rotateArr(int arr[], int d) {
        int n = arr.length;
        d %= n;
        reverse(arr, 0, d - 1);
        reverse(arr, d, n - 1);
        reverse(arr, 0, n - 1);
    }

    static void reverse(int[] arr, int start, int end) {
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
    def rotateArr(self, arr, d):
        n = len(arr)
        d %= n
        arr[0:d] = reversed(arr[0:d])
        arr[d:n] = reversed(arr[d:n])
        arr[0:n] = reversed(arr[0:n])
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
