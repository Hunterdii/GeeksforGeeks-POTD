# _02. Subarrays with Sum K_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1)

## Problem Description

Given an unsorted array of integers, find the number of continuous subarrays having a sum exactly equal to a given number `k`.

**Examples:**

Input:

```
arr = [10, 2, -2, -20, 10], k = -10
```

Output:

```
3
```

Explanation: Subarrays: `arr[0...3]`, `arr[1...4]`, and `arr[3...4]` have a sum exactly equal to `-10`.

Input:

```
arr = [9, 4, 20, 3, 10, 5], k = 33
```

Output:

```
2
```

Explanation: Subarrays: `arr[0...2]` and `arr[2...4]` have a sum exactly equal to `33`.

Input:

```
arr = [1, 3, 5], k = 0
```

Output:

```
0
```

Explanation: No subarray has a sum of `0`.

**Constraints:**

- $\(1 \leq \text{arr.size()} \leq 10^5\)$
- $\(-10^3 \leq \text{arr[i]} \leq 10^3\)$
- $\(-10^7 \leq k \leq 10^7\)$

## My Approach

To solve this problem efficiently:

1. **Prefix Sum with Hash Map:**

   - Maintain a running sum (`sum`) as you traverse the array.
   - Use a hash map (`prefixSumCount`) to store the count of prefix sums encountered so far.
   - For each element, check if the difference `sum - k` exists in the hash map. If it does, it means there is a subarray ending at the current index with a sum equal to `k`.

2. **Increment Hash Map:**

   - Add the current running sum to the hash map or increment its count if it already exists.

3. **Count Matching Subarrays:**

   - Increment the count by the number of times `sum - k` has been encountered so far.

4. **Final Answer:**
   - The variable `count` will hold the number of subarrays with a sum equal to `k`.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n)\), as we traverse the array once and perform \(O(1)\) operations for each element.
- **Expected Auxiliary Space Complexity:** \(O(n)\), to store the hash map containing prefix sums.

## Code (C++)

```cpp
class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount = {{0, 1}};
        int sum = 0, count = 0;

        for (int num : arr) {
            sum += num;
            count += prefixSumCount[sum - k];
            prefixSumCount[sum]++;
        }

        return count;
    }
};
```

## Code (Java)

```java
class Solution {
    public int countSubarrays(int[] arr, int k) {
        Map<Integer, Integer> prefixSumCount = new HashMap<>();
        prefixSumCount.put(0, 1);
        int sum = 0, count = 0;

        for (int num : arr) {
            sum += num;
            count += prefixSumCount.getOrDefault(sum - k, 0);
            prefixSumCount.put(sum, prefixSumCount.getOrDefault(sum, 0) + 1);
        }

        return count;
    }
}
```

## Code (Python)

```python
class Solution:
    def countSubarrays(self, arr, k):
        prefix_sum_count = {0: 1}
        sum_, count = 0, 0

        for num in arr:
            sum_ += num
            count += prefix_sum_count.get(sum_ - k, 0)
            prefix_sum_count[sum_] = prefix_sum_count.get(sum_, 0) + 1

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
