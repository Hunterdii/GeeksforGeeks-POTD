## 14. Xoring and Clearing

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/xoring-and-clearing/1)

### Problem Description

You are given an array `arr[]` of size \(n\). You need to do the following:

1. Calculate the bitwise XOR of each element in the array with its corresponding index (indices start from 0).
2. After step 1, print the array.
3. Set all the elements of `arr[]` to zero.
4. Print `arr[]` after setting all elements to zero.

**Example 1:**

Input:

```
n = 10
arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
```

Output:

```
1 3 1 7 1 3 1 15 1 3
0 0 0 0 0 0 0 0 0 0
```

Explanation:

- First, we take the XOR of every element with their indices, like \( (1 \oplus 0), (2 \oplus 1), (3 \oplus 2), (4 \oplus 3) \), and so on.
- Now print the resultant array.
- Now set all the elements of the array to zero.
- Now print the resultant array.

### My Approach

1. **XOR Calculation:**

   - Iterate through the array and calculate the bitwise XOR of each element with its corresponding index.

2. **Printing:**
   - Print the array after XOR calculation.
3. **Set to Zero:**

   - Set all the elements of the array to zero.

4. **Printing:**
   - Print the array after setting all elements to zero.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array once to perform XOR calculation and set elements to zero.
- **Expected Auxiliary Space Complexity:** O(1), as we do not use any extra space that grows with the input size.

### Code (C++)

```cpp
class Solution {
public:
    void printArr(int n, int arr[]) {
        for (int i = 0; i < n; i++) {
            std::cout << (arr[i]) << " ";
        }
        std::cout << std::endl;
    }

    void setToZero(int n, int arr[]) {
        std::fill(arr, arr + n, 0);
    }

    void xor1ToN(int n, int arr[]) {
        for (int i = 0; i < n; i++) {
            arr[i] ^= i;
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
