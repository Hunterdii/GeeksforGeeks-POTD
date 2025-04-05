# _11. Reorganize The Array_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reorganize-the-array4810/1)

### **Problem Description**

Given an array `arr[]` with indices ranging from `0` to `arr.size() - 1`, rearrange the elements such that for each index `i`, `arr[i] = i`. If an element `i` is not present in the array, place `-1` at that index.

#### **Example:**

**Input 1:**

```python
arr[] = [-1, -1, 6, 1, 9, 3, 2, -1, 4, -1]
```

**Output 1:**

```python
[-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]
```

**Explanation:**

- In the original array, elements are arranged out of order. After rearranging, we place the element `i` in its index position.
- Elements `0, 5, 7, 8` are missing from the array, so `-1` is placed in those positions.

### **My Approach**

1. **Iterate Through the Array:**  
   We will traverse the array and check if each element is in the correct position. If not, we will rearrange the elements by placing them in the correct index.
2. **Handling Missing Elements:**  
   If an element is not found in the array or if it's a negative value, we place `-1` at the corresponding index.

3. **Time and Space Complexity:**  
   Since the problem requires us to modify the array in-place, we will minimize the space used by only utilizing extra space where necessary.

---

### **Time Complexity**

- **Expected Time Complexity:**  
  O(n), where `n` is the size of the array, as we only traverse the array once and perform constant time operations on each element.
- **Expected Auxiliary Space Complexity:**  
  O(1), as we are performing the rearrangement in-place and using only a constant amount of additional space.

---

### **Code Implementation**

#### **C++:**

```cpp
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= 0 && arr[i] < n) {
                result[arr[i]] = arr[i];
            }
        }

        return result;
    }
};
```

---

#### **Java:**

```java
class Solution {
    public List<Integer> rearrange(List<Integer> arr) {
        int n = arr.size();
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            result.add(-1);
        }
        for (int i = 0; i < n; i++) {
            int value = arr.get(i);
            if (value >= 0 && value < n) {
                result.set(value, value);
            }
        }

        return result;
    }
}
```

---

#### **Python:**

```python
class Solution:
    def rearrange(self, arr):
        n = len(arr)
        result = [-1] * n
        for i in range(n):
            if 0 <= arr[i] < n:
                result[arr[i]] = arr[i]

        return result
```

---

### **Contribution and Support**

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
