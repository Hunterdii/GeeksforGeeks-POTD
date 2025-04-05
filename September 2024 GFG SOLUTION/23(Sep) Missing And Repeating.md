# _23. Missing and Repeating_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1)

### Problem Description

Given an unsorted array `arr` of positive integers where one number 'A' from the set {1, 2,..., n} is missing, and one number 'B' occurs twice in the array, find the numbers A and B.

#### Example 1:

**Input:**

    arr[] = [2, 2]

**Output:**

    2 1

**Explanation:**

    Repeating number is 2, and the smallest positive missing number is 1.

#### Example 2:

**Input:**

    arr[] = [1, 3, 3]

**Output:**

    3 2

**Explanation:**

    Repeating number is 3, and the smallest positive missing number is 2.

#### Constraints:

- 2 ≤ n ≤ 10^5
- 1 ≤ arr[i] ≤ n

### My Approach

1. **XOR Logic:**
   - We XOR all the elements of the array and all numbers from 1 to n. The result will be `xor_all`, which is the XOR of the repeating and the missing numbers.
   - Find the rightmost set bit in `xor_all`. This will help separate the missing and repeating numbers into two different sets based on whether they have the bit set or not.
2. **Separate Sets:**
   - Traverse the array again and XOR the elements that belong to the same set, resulting in two XOR results (`xor1` and `xor2`). These will represent the missing and repeating numbers.
3. **Final Step:**
   - Determine which of `xor1` or `xor2` is the repeating number by checking the input array, and deduce the missing number.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the size of the array. We traverse the array a constant number of times.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

---

### Code (C++)

```cpp
class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int xor_all = 0, xor1 = 0, xor2 = 0;
        for (int i = 0; i < n; i++) {
            xor_all ^= arr[i];
            xor_all ^= (i + 1);
        }
        int set_bit = xor_all & ~(xor_all - 1);
        for (int i = 0; i < n; i++) {
            if (arr[i] & set_bit)
                xor1 ^= arr[i];
            else
                xor2 ^= arr[i];

            if ((i + 1) & set_bit)
                xor1 ^= (i + 1);
            else
                xor2 ^= (i + 1);
        }
        int repeating, missing;
        for (int i = 0; i < n; i++) {
            if (arr[i] == xor1) {
                repeating = xor1;
                missing = xor2;
                break;
            } else if (arr[i] == xor2) {
                repeating = xor2;
                missing = xor1;
                break;
            }
        }

        return {repeating, missing};
    }
};
```

---

### Code (Java)

```java
class Solve {
    int[] findTwoElement(int arr[]) {
        int n = arr.length;
        int xor_all = 0, xor1 = 0, xor2 = 0;

        for (int i = 0; i < n; i++) {
            xor_all ^= arr[i];
            xor_all ^= (i + 1);
        }

        int set_bit = xor_all & ~(xor_all - 1);

        for (int i = 0; i < n; i++) {
            if ((arr[i] & set_bit) != 0)
                xor1 ^= arr[i];
            else
                xor2 ^= arr[i];

            if (((i + 1) & set_bit) != 0)
                xor1 ^= (i + 1);
            else
                xor2 ^= (i + 1);
        }

        int repeating = 0, missing = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == xor1) {
                repeating = xor1;
                missing = xor2;
                break;
            } else if (arr[i] == xor2) {
                repeating = xor2;
                missing = xor1;
                break;
            }
        }

        return new int[]{repeating, missing};
    }
}
```

---

### Code (Python)

```python
class Solution:
    def findTwoElement(self, arr):
        n = len(arr)
        xor_all = 0
        xor1 = 0
        xor2 = 0

        for i in range(n):
            xor_all ^= arr[i]
            xor_all ^= (i + 1)

        set_bit = xor_all & ~(xor_all - 1)

        for i in range(n):
            if (arr[i] & set_bit) != 0:
                xor1 ^= arr[i]
            else:
                xor2 ^= arr[i]

            if ((i + 1) & set_bit) != 0:
                xor1 ^= (i + 1)
            else:
                xor2 ^= (i + 1)

        repeating, missing = 0, 0
        for i in range(n):
            if arr[i] == xor1:
                repeating = xor1
                missing = xor2
                break
            elif arr[i] == xor2:
                repeating = xor2
                missing = xor1
                break

        return [repeating, missing]
```

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
