# _07. Pair with Given Sum in a Sorted Array_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1)

## Problem Description

You are given a sorted array `arr[]` of size `n` and an integer `target`. Your task is to find the number of pairs `(i, j)` such that `arr[i] + arr[j] = target`, where `i` and `j` are distinct indices (`i ≠ j`).

## Examples:

**Input:**  
`arr[] = [-1, 1, 5, 5, 7], target = 6`  
**Output:**  
`3`  
**Explanation:**  
The pairs `(1, 5)`, `(1, 5)`, and `(-1, 7)` sum up to `6`.

**Input:**  
`arr[] = [1, 1, 1, 1], target = 2`  
**Output:**  
`6`  
**Explanation:**  
There are 6 pairs: `(1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1)`.

**Input:**  
`arr[] = [-1, 10, 10, 12, 15], target = 125`  
**Output:**  
`0`  
**Explanation:**  
No such pairs exist.

### Constraints:

- $`2 <= arr.size() <= 10^5`$
- $`-10^5 <= arr[i] <= 10^5`$
- $`-10^5 <= target <= 10^5`$

## My Approach

1. **Efficient Pair Counting Using a Hash Map**:

   - This approach leverages a hash map to store the frequency of elements as we traverse the array.
   - For each element `x` in the array, the complement required to form a pair is `target - x`.
   - We check if the complement exists in the hash map. If yes, the frequency of the complement contributes to the count of valid pairs.
   - Update the frequency of `x` in the hash map.

2. **Steps:**
   - Initialize an empty hash map `freq` to store the frequency of elements.
   - Traverse the array and for each element:
     - Check if the complement (`target - x`) exists in the hash map.
     - Add the frequency of the complement to the result.
     - Update the frequency of the current element in the hash map.
   - Return the total count of pairs.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the array. Each element is processed once, and hash map operations (insertions and lookups) take O(1) on average.
- **Expected Auxiliary Space Complexity:** O(n), as we store the frequency of up to `n` elements in the hash map.

## Code (C++)

```cpp
class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        unordered_map<int, int> freq;
        int res = 0;

        for (int num : arr) {
            int complement = target - num;
            if (freq.count(complement))
                res += freq[complement];

            freq[num]++;
        }

        return res;
    }
};
```

## Code (Java)

```java
class Solution {
    int countPairs(int[] arr, int target) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        int res = 0;

        for (int num : arr) {
            res += freq.getOrDefault(target - num, 0);
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        return res;
    }
}
```

## Code (Python)

```python
class Solution:
    def countPairs(self, arr, target):
        freq = {}
        res = 0

        for num in arr:
            res += freq.get(target - num, 0)
            freq[num] = freq.get(num, 0) + 1

        return res
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
