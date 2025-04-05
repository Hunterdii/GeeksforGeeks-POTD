## 10. Combination Sum II

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/combination-sum-ii-1664263832/1)

### Problem Description

Given an array of integers `arr`, the length of the array `n`, and an integer `k`, find all the unique combinations in `arr` where the sum of the combination is equal to `k`. Each number can only be used once in a combination.

**Example 1:**

Input:

```
n = 5, k = 7
arr[] = {1, 2, 3, 3, 5}
```

Output:

```
{{1, 3, 3}, {2, 5}}
```

Explanation:
1 + 3 + 3 = 7
2 + 5 = 7

**Example 2:**

Input:

```
n = 6, k = 35
arr[] = {5, 10, 15, 20, 25, 30}
```

Output:

```
{{5, 10, 20}, {5, 30}, {10, 25}, {15, 20}}
```

Explanation:
5 + 10 + 20 = 35
5 + 30 = 35
10 + 25 = 35
15 + 20 = 35

### My Approach

1. **Sorting:**

- Sort the input array `arr` to easily handle duplicates and optimize the search.

2. **Backtracking:**

- Implement a backtracking algorithm to find all combinations whose sum equals `k`.
- Start iterating through the array, trying each element as a potential starting point for a combination.
- Recursively explore all possible combinations by adding elements to the current combination and adjusting the target sum accordingly.
- Skip duplicate elements to avoid duplicate combinations.
- When the target sum becomes zero, add the current combination to the result.

3. **Return:**

- Return the vector containing all unique combinations.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(2^(min(n,p))), where \(p\) is the number of elements that, at maximum, can sum up to the given value \(k\).
- **Expected Auxiliary Space Complexity:** O(n), where \(n\) is the size of the input array.

### Code (C++)

```cpp
class Solution{
public:
    void solve(vector<int>& arr, int target, int start, vector<int>& temp, vector<vector<int>>& result) {
        if(target == 0) {
            result.push_back(temp);
            return;
        }

        for(int i = start; i < arr.size(); i++) {
            if(i > start && arr[i] == arr[i - 1])
                continue;

            if(arr[i] > target)
                break;

            temp.push_back(arr[i]);
            solve(arr, target - arr[i], i + 1, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(arr, k, 0, temp, result);
        return result;
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
