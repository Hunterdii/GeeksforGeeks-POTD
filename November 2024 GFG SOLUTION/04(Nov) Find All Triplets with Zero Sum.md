# _04. Find All Triplets with Zero Sum_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1)

## Problem Description

Given an array `arr[]`, find all possible indices `[i, j, k]` of triplets `[arr[i], arr[j], arr[k]]` in the array whose sum is equal to zero. Return indices of triplets in any order, and all the returned triplet indices should also be internally sorted, i.e., for any triplet indices `[i, j, k]`, the condition `i < j < k` should hold.

#### Examples:

**Input:**  
`arr[] = [0, -1, 2, -3, 1]`  
**Output:**  
`[[0, 1, 4], [2, 3, 4]]`  
**Explanation:** Triplets with sum 0 are:  
`arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0`  
`arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0`

**Input:**  
`arr[] = [1, -2, 1, 0, 5]`  
**Output:**  
`[[0, 1, 2]]`  
**Explanation:** Only triplet which satisfies the condition is:  
`arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0`

**Input:**  
`arr[] = [2, 3, 1, 0, 5]`  
**Output:**  
`[[]]`  
**Explanation:** There is no triplet with sum 0.

## My Approach

1. **Using Hash Map for Index Storage:**

   - Create a hash map to store the indices of elements in the array.
   - Traverse the array and populate the map with indices of each element.

2. **Finding Triplets:**

   - Use two nested loops to select pairs of elements. For each pair, calculate the negation of their sum.
   - Check if this value exists in the hash map and ensure that the index of this element is greater than the current indices to maintain the condition `i < j < k`.

3. **Returning the Triplets:**
   - Collect the valid triplet indices into a result list and return it.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n²), where n is the size of the array, as we use two loops to find pairs and lookup in the hash map.
- **Expected Auxiliary Space Complexity:** O(n), as we store the indices of the elements in the hash map.

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[arr[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int num = -1 * (arr[i] + arr[j]);
                if (mp.find(num) != mp.end()) {
                    for (auto it : mp[num]) {
                        if (it > j) ans.push_back({i, j, it});
                    }
                }
            }
        }
        return ans;
    }
};
```

## Code (Java)

```java
class Solution {
    public List<List<Integer>> findTriplets(int[] arr) {
        int n = arr.length;
        Map<Integer, List<Integer>> mp = new HashMap<>();
        List<List<Integer>> ans = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            mp.putIfAbsent(arr[i], new ArrayList<>());
            mp.get(arr[i]).add(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int num = -(arr[i] + arr[j]);
                if (mp.containsKey(num)) {
                    for (int index : mp.get(num)) {
                        if (index > j) {
                            ans.add(Arrays.asList(i, j, index));
                        }
                    }
                }
            }
        }

        return ans;
    }
}
```

## Code (Python)

```python
class Solution:
    def findTriplets(self, arr):
        n = len(arr)
        mp = {}
        ans = []

        for i in range(n):
            if arr[i] not in mp:
                mp[arr[i]] = []
            mp[arr[i]].append(i)

        for i in range(n):
            for j in range(i + 1, n):
                num = -(arr[i] + arr[j])
                if num in mp:
                    for index in mp[num]:
                        if index > j:
                            ans.append([i, j, index])

        return ans
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
