# _21. Split the Array_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/split-the-array0238/1)

### **Problem Description**

Given an array `arr[]` of integers, the task is to count the number of ways to split the array elements into two non-empty subsets such that the XOR of elements in each group is equal. Each element should belong to exactly one subset.

**Note:**

- The answer could be very large, so print it modulo \(10^9 + 7\).
- Subsets with the same elements but derived from different indices are different.

#### **Examples:**

**Input:**

    arr[] = [1, 2, 3]

**Output:**

    3

**Explanation:**
The three ways to split the array are:

- (1), (2, 3)
- (2), (1, 3)
- (3), (1, 2)

### **My Approach**

1. **Understanding XOR and Subset Splitting:**

   - XOR operation exhibits a unique property: \( a \oplus a = 0 \), which means that to split the array into two subsets with equal XOR, the total XOR of the entire array must be 0. This is because we need the XORs of both subsets to be equal, and if the total XOR of the array is non-zero, it will be impossible to partition it into equal XOR subsets.

2. **Total XOR Check:**
   - Compute the XOR of all elements in the array. If the XOR of the entire array is not zero, return 0 immediately as it is impossible to split the array into two groups with equal XOR.
3. **Counting Ways to Split:**
   - If the XOR of the entire array is 0, then there are valid ways to split the array.
   - The number of ways to split the array can be computed as \(2^{n-1} - 1\) because every non-empty subset can potentially participate in the split, but we need to exclude cases where one subset is empty.
   - The result is calculated modulo \(10^9 + 7\).

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n log p), where ( n ) is the length of the array and ( p = 10^9 + 7 ), due to the modular exponentiation operation.
- **Expected Auxiliary Space Complexity:** O(1), as only a few variables are used to store intermediate results.

---

### **Code (C++)**

```cpp
class Solution {
public:
    int power(int x, int y, int p) {
        int result = 1;
        x = x % p;
        while (y > 0) {
            if (y & 1)
                result = (result * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return result;
    }

    int countgroup(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        int xs = 0;
        for (int num : arr) {
            xs ^= num;
        }
        if (xs == 0) {
            return (power(2, n - 1, mod) - 1 + mod) % mod;
        }
        return 0;
    }
};
```

### **Code (Java)**

```java
class Solution {
    public int power(int x, int y, int p) {
        int result = 1;
        x = x % p;
        while (y > 0) {
            if ((y & 1) == 1)
                result = (result * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return result;
    }

    public int countgroup(int[] arr) {
        int mod = 1000000007;
        int n = arr.length;
        int xs = 0;
        for (int num : arr) {
            xs ^= num;
        }
        if (xs == 0) {
            return (power(2, n - 1, mod) - 1 + mod) % mod;
        }
        return 0;
    }
}
```

### **Code (Python)**

```python
class Solution:
    def power(self, x, y, p):
        result = 1
        x = x % p
        while y > 0:
            if y & 1:
                result = (result * x) % p
            y >>= 1
            x = (x * x) % p
        return result

    def countgroup(self, arr):
        mod = 1000000007
        n = len(arr)
        xs = 0
        for num in arr:
            xs ^= num
        if xs == 0:
            return (self.power(2, n - 1, mod) - 1 + mod) % mod
        return 0
```

### **Contribution and Support**

For discussions, questions, or doubts related to this solution, feel free to reach out to me via [LinkedIn](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input and support.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
