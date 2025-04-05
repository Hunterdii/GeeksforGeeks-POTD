# _18. Single Number_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/single-number1014/1)

### **Problem Description**

Given an array `arr[]` of positive integers where every element appears an even number of times except for one. Find that number occurring an odd number of times.

_Example 1:_

Input: `arr[] = [1, 1, 2, 2, 2]`  
Output: `2`  
Explanation: In the given array, all elements appear twice except for `2`, which appears three times.

_Example 2:_

Input: `arr[] = [8, 8, 7, 7, 6, 6, 1]`  
Output: `1`  
Explanation: In the given array, all elements appear twice except for `1`, which appears only once.

### **Constraints:**

- 1 ≤ arr.size() ≤ 10^6
- 0 ≤ arr[i] ≤ 10^5

### **My Approach**

1. **XOR Principle**:  
   XORing the same number twice results in zero. Hence, XORing all elements of the array together will cancel out all numbers that appear an even number of times, leaving behind the number that appears an odd number of times.

2. **Implementation**:

   - Initialize a variable `xr` to 0.
   - Iterate through the array, XOR each element with `xr`. The final result will be the number that occurs an odd number of times.

3. **Why XOR Works**:
   - XOR operation satisfies the properties of commutativity and associativity, which makes it a perfect fit for this problem. Repeated elements cancel each other out, leaving only the unique element.

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), as we traverse the array once to compute the XOR of all elements, where `n` is the size of the array.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of space to store the XOR result.

### **Code (C++)**

```cpp
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int xr = 0;
        for (int num : arr) {
            xr ^= num;
        }
        return xr;
    }
};
```

### **Code (Java)**

```java
class Solution {
    int getSingle(int arr[]) {
        int xr = 0;
        for (int num : arr) {
            xr ^= num;
        }
        return xr;
    }
}
```

### **Code (Python)**

```python
class Solution:
    def getSingle(self, arr):
        xr = 0
        for num in arr:
            xr ^= num
        return xr
```

---

## **Contribution and Support**

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
