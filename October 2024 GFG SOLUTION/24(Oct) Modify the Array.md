# _24. Modify the Array_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/ease-the-array0633/1)

### Problem Description

Given an array `arr`, return the modified array in such a way that if the current and next numbers are valid (non-zero) and are equal, then double the current number's value and replace the next number with 0. After the modification, rearrange the array such that all 0s are shifted to the end.

_Note:_ Assume '0' as the invalid number and all others as valid numbers. The sequence of valid numbers should remain in the same order.

#### Example:

Input:

```
arr[] = [2, 2, 0, 4, 0, 8]
```

Output:

```
[4, 4, 8, 0, 0, 0]
```

Explanation: At index 0 and 1, both elements are the same. Thus, the element at index 0 becomes 4, and the element at index 1 becomes 0. After shifting all the zeros to the end, the array becomes `[4, 4, 8, 0, 0, 0]`.

Input:

```
arr[] = [0, 2, 2, 2, 0, 6, 6, 0, 0, 8]
```

Output:

```
[4, 2, 12, 8, 0, 0, 0, 0, 0, 0]
```

Explanation: At index 5 and 6, both elements are the same. Thus, the element at index 5 becomes 12, and the element at index 6 becomes 0. Then, at index 1 and 2, both elements are the same. The element at index 1 becomes 4, and the element at index 2 becomes 0. After shifting all the zeros to the end, the array becomes `[4, 2, 12, 8, 0, 0, 0, 0, 0, 0]`.

### My Approach

1. **Iterate through the array:**

   - For each element, check if it is not zero and if it is equal to the next element. If both conditions are true, double the current element and set the next element to zero.

2. **Rearranging the array:**
   - Create a new index to keep track of the position of non-zero elements. First, move all non-zero elements to the beginning of the array, and then fill the remaining positions with zeros.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the array once for modification and once for rearranging the non-zero elements.
- **Expected Auxiliary Space Complexity:** O(n), since we may use extra space to store the result.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> modifyAndRearrangeArray(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] = 2 * arr[i];
                arr[i + 1] = 0;
            }
        }

        int nonZeroIndex = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[nonZeroIndex++] = arr[i];
            }
        }

        while (nonZeroIndex < n) {
            arr[nonZeroIndex++] = 0;
        }

        return arr;
    }
};
```

### Code (Java)

```java
class Solution {
    static ArrayList<Integer> modifyAndRearrangeArr(int[] arr) {
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] = 2 * arr[i];
                arr[i + 1] = 0;
            }
        }

        int nonZeroIndex = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[nonZeroIndex++] = arr[i];
            }
        }

        while (nonZeroIndex < n) {
            arr[nonZeroIndex++] = 0;
        }

        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            result.add(arr[i]);
        }

        return result;
    }
}
```

### Code (Python)

```python
class Solution:
    def modifyAndRearrangeArr(self, arr):
        n = len(arr)

        for i in range(n - 1):
            if arr[i] != 0 and arr[i] == arr[i + 1]:
                arr[i] = 2 * arr[i]
                arr[i + 1] = 0

        nonZeroIndex = 0
        for i in range(n):
            if arr[i] != 0:
                arr[nonZeroIndex] = arr[i]
                nonZeroIndex += 1

        while nonZeroIndex < n:
            arr[nonZeroIndex] = 0
            nonZeroIndex += 1

        return arr
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
