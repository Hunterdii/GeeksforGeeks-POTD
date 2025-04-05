# _02. Rotate and Delete_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1)

### Problem Description

Given an array of integers `arr`, perform the following operation until only a single element remains:

For every k-th operation:

1. Rotate the array clockwise by 1 position.
2. Delete the (z - k + 1)-th element, where z is the original size of the array.

Return the last remaining element in the array.

**Example:**

Input:

```
arr = [1, 2, 3, 4, 5, 6]
```

Output:

```
3
```

**Explanation:** After rotating and deleting as per the specified rules, the last element left is 3.

### My Approach

1. **Rotation and Deletion:**

   - For each operation, rotate the array clockwise, effectively moving the last element to the front.
   - Calculate the index of the element to delete based on the current size of the array and the current operation count.

2. **Loop Until One Element Remains:**

   - Continue this process until only one element remains in the array.

3. **Return the Result:**
   - The remaining element after all operations will be the answer.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n²), as for each of the n elements, we might perform a rotation and a deletion operation which can take up to O(n) time.
- **Expected Auxiliary Space Complexity:** O(1), as we are using a constant amount of extra space for variables regardless of the size of the input array.

### Code (C++)

```cpp
class Solution {
public:
    int rotateDelete(vector<int> &arr) {
        int i = 1;
        int n = arr.size();
        while (i < (n / 2) + 1) {
            rotate(arr.begin(), arr.end() - 1, arr.end());
            arr.erase(arr.begin() + (arr.size() - i));
            i++;
        }
        return arr[0];
    }
};
```

### Code (Java)

```java
class Solution {
    public static int rotateDelete(ArrayList<Integer> arr) {
        int n = arr.size(), k = 1;
        while (n > 1) {
            arr.add(0, arr.remove(n - 1));
            int id = n - k;
            if (id < 0) id = 0;
            arr.remove(id);
            k++;
            n--;
        }
        return arr.get(0);
    }
}
```

### Code (Python)

```python
class Solution:
    def rotateDelete(self, arr):
        n = len(arr)
        k = 1
        while n > 1:
            arr.insert(0, arr.pop())
            id = n - k
            if id < 0:
                id = 0
            arr.pop(id)
            k += 1
            n -= 1

        return arr[0]
```

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
