# _30. Pairs with Difference k_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pairs-with-difference-k1713/1)

### Problem Description

Given an array `arr[]` of positive integers, find the number of pairs of integers whose difference equals a given number `k`. Note that `(a, b)` and `(b, a)` are considered the same, and the same numbers at different indices are considered different.

**Example:**

Input:

```plaintext
arr = [1, 5, 3, 4, 2]
k = 3
```

Output:

```plaintext
2
```

Explanation: There are 2 pairs with difference 3, namely {1, 4} and {5, 2}.

Input:

```plaintext
arr = [8, 12, 16, 4, 0, 20]
k = 4
```

Output:

```plaintext
5
```

Explanation: There are 5 pairs with difference 4: {0, 4}, {4, 8}, {8, 12}, {12, 16}, and {16, 20}.

## Constraint

- (1 leq text{arr.size()} leq 10^6)
- (1 leq k leq 10^6)
- (1 leq text{arr[i]} leq 10^6)

## My Approach

1. **Hashing for Efficient Lookup:**

   - Use an unordered set (or hash set) to store unique elements of `arr`.
   - This allows \(O(1)\) time complexity for searching whether an element plus the difference `k` exists in the set.

2. **Counting Pairs with Difference `k`:**

   - Iterate through each unique element in the set.
   - For each element `x`, check if `x + k` exists in the set.
   - If `x + k` exists, calculate the occurrences of `x` and `x + k` in `arr`, and add their product to the total count.

3. **Avoiding Double Counting:**
   - To ensure unique pairs are counted correctly, only consider each pair `(x, x + k)` once by iterating over the set.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n)\), where \(n\) is the length of `arr`, as we use a hash set for constant time checks and loop through each unique element.
- **Expected Auxiliary Space Complexity:** \(O(n)\), due to the hash set storing unique elements from `arr`.

### Code (C++)

```cpp
class Solution {
public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_set<int> numSet(arr.begin(), arr.end());
        int count = 0;

        for (int x : numSet) {
            if (numSet.find(x + k) != numSet.end()) {
                count += count_if(arr.begin(), arr.end(), [x](int n){ return n == x; }) *
                         count_if(arr.begin(), arr.end(), [x, k](int n){ return n == x + k; });
            }
        }

        return count;
    }
};
```

### Code (Java)

```java
class Solution {
    public int countPairsWithDiffK(int[] arr, int k) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : arr) {
            numSet.add(num);
        }

        int count = 0;
        for (int x : numSet) {
            if (numSet.contains(x + k)) {
                int countX = 0;
                int countXPlusK = 0;
                for (int num : arr) {
                    if (num == x) countX++;
                    if (num == x + k) countXPlusK++;
                }
                count += countX * countXPlusK;
            }
        }

        return count;
    }
}
```

### Code (Python)

```python
class Solution:
    def countPairsWithDiffK(self, arr, k):
        num_set = set(arr)
        count = 0

        for x in num_set:
            if (x + k) in num_set:
                count += arr.count(x) * arr.count(x + k)

        return count
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
