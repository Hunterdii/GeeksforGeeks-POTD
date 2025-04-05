# _02. Kth Distance_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/kth-distance3757/1)

## Problem Description

Given an unsorted array `arr` and a number `k` which is smaller than the size of the array, return true if the array contains any duplicate within `k` distance throughout the array; otherwise, return false.

_Example:_

Input:

```
arr[] = [1, 2, 3, 4, 1, 2, 3, 4] and k = 3
```

Output:

```
false
```

Explanation: All duplicates are more than `k` distance away.

Input:

```
arr[] = [1, 2, 3, 1, 4, 5] and k = 3
```

Output:

```
true
```

Explanation: `1` is repeated at distance `3`.

Input:

```
arr[] = [6, 8, 4, 1, 8, 5, 7] and k = 3
```

Output:

```
true
```

Explanation: `8` is repeated at distance `3`.

## Constraints

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ k < arr.size()`
- `1 ≤ arr[i] ≤ 10^5`

## My Approach

1. **Using a Hash Map:**

   - Create a hash map to store the last index of each element encountered in the array.

2. **Iterate Through the Array:**

   - For each element, check if it exists in the map.
   - If it does, check the difference between the current index and the stored index of that element. If the difference is less than or equal to `k`, return true.
   - Otherwise, update the last index of that element in the map.

3. **Final Result:**
   - If no duplicates are found within `k` distance, return false.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the length of the array, as we traverse the array once.
- **Expected Auxiliary Space Complexity:** O(min(n, k)), since the hash map will store at most `k` elements at any time.

## Code (C++)

```cpp
class Solution {
public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++) {
            if (mp.count(arr[i]) && i - mp[arr[i]] <= k) {
                return true;
            }
            mp[arr[i]] = i;
        }

        return false;
    }
};
```

## Code (Java)

```java
class Solution {
    public boolean checkDuplicatesWithinK(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(arr[i]) && i - map.get(arr[i]) <= k) {
                return true;
            }
            map.put(arr[i], i);
        }

        return false;
    }
}
```

## Code (Python)

```python
class Solution:
    def checkDuplicatesWithinK(self, arr, k):
        mp = {}

        for i in range(len(arr)):
            if arr[i] in mp and i - mp[arr[i]] <= k:
                return True
            mp[arr[i]] = i

        return False
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
