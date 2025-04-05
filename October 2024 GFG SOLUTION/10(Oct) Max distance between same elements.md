# _10. Max Distance Between Same Elements_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/max-distance-between-same-elements/1)

### Problem Description

Given an array `arr[]` with repeated elements, the task is to find the maximum distance between two occurrences of any element.

_Note:_ The array is guaranteed to contain at least one repeating element.

#### Examples:

**Input:**  
`arr = [1, 1, 2, 2, 2, 1]`  
**Output:**  
`5`  
**Explanation:**  
The distance between the first and last occurrence of 1 is `5 - 0 = 5`.  
For 2, the maximum distance is `4 - 2 = 2`.  
Thus, the maximum distance is 5.

**Input:**  
`arr = [3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2]`  
**Output:**  
`10`  
**Explanation:**  
For 2, the maximum distance is `11 - 1 = 10`.  
For 1, the maximum distance is `4 - 2 = 2`.  
For 4, the maximum distance is `10 - 5 = 5`.  
Thus, the maximum distance is 10.

### Approach

1. **Tracking First Occurrences:**
   - We iterate through the array and maintain a hash map to store the first occurrence of each element.
2. **Calculating Maximum Distance:**
   - For each element, if it appears again in the array, we calculate the distance between its current index and the first occurrence stored in the hash map. We update the maximum distance accordingly.
3. **Final Result:**
   - After iterating through the array, the maximum distance found will be the result.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** `O(n)`, where `n` is the size of the array. We traverse the array once and perform constant-time operations (hash map lookups and updates) for each element.
- **Expected Auxiliary Space Complexity:** `O(n)`, as we store the first occurrence of each unique element in the hash map.

### Code (C++)

```cpp
class Solution {
public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> mp;
        int max_dist = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = i;
            } else {
                max_dist = max(max_dist, i - mp[arr[i]]);
            }
        }
        return max_dist;
    }
};
```

### Code (Java)

```java
class Solution {
    public int maxDistance(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int max_dist = 0;
        for (int i = 0; i < arr.length; i++) {
            if (!map.containsKey(arr[i])) {
                map.put(arr[i], i);
            } else {
                max_dist = Math.max(max_dist, i - map.get(arr[i]));
            }
        }
        return max_dist;
    }
}
```

### Code (Python)

```python
class Solution:
    def maxDistance(self, arr):
        mp = {}
        max_dist = 0
        for i in range(len(arr)):
            if arr[i] not in mp:
                mp[arr[i]] = i
            else:
                max_dist = max(max_dist, i - mp[arr[i]])

        return max_dist
```

## Contribution and Support

For any questions or discussions about this solution, feel free to reach out to me on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's keep learning and improving together!

⭐ **Star** this repository if you find the solutions helpful! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
