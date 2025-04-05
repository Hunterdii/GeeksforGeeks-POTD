# _22. Sub-arrays with Equal Number of Occurrences_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sub-arrays-with-equal-number-of-occurences3901/1)

### Problem Description

Given an array `arr[]` and two integers `x` and `y`, find the number of sub-arrays where the number of occurrences of `x` is equal to the number of occurrences of `y`.

#### Example:

**Input:**

```
arr = [1, 2, 1], x = 1, y = 2
```

**Output:**

```
2
```

**Explanation:**

- The sub-arrays where the occurrences of `x` and `y` are the same are:
  - `[1, 2]`, both `x` and `y` occur once.
  - `[2, 1]`, both `x` and `y` occur once.

**Input:**

```
arr = [1, 2, 1], x = 4, y = 6
```

**Output:**

```
6
```

**Explanation:**

- All sub-arrays have equal occurrences (0) of both `x` and `y`.

### My Approach

1. **Prefix Difference Array:**

   - Create a difference count (`diffCount`) to store the difference between occurrences of `x` and `y` at every index.
   - We maintain a running `diff` that increases by 1 when `x` occurs and decreases by 1 when `y` occurs. This helps track sub-arrays where `x` and `y` appear an equal number of times.
   - The goal is to find how many times the same `diff` has appeared in `diffCount`, which means there exists a sub-array between these two occurrences where the number of `x` and `y` occurrences are equal.

2. **Efficient HashMap Usage:**

   - Use a hash map to store the occurrences of the differences at each step.
   - For each index, the value of the current difference in `diffCount` gives the number of sub-arrays that maintain the equal occurrence of `x` and `y`.

3. **Result Accumulation:**
   - Increment the result by the number of times the current `diff` has been seen.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the array. We iterate through the array once and use a hash map to store prefix sums.
- **Expected Auxiliary Space Complexity:** O(n), as we store the differences in a hash map.

### Code (C++)

```cpp
class Solution {
public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        unordered_map<int, int> diffCount;
        int diff = 0;
        int result = 0;

        diffCount[0] = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) diff++;
            else if (arr[i] == y) diff--;

            result += diffCount[diff];

            diffCount[diff]++;
        }

        return result;
    }
};
```

### Code (Java)

```java
class Solution {

    static int sameOccurrence(int[] arr, int x, int y) {
        HashMap<Integer, Integer> diffCount = new HashMap<>();
        int diff = 0;
        int result = 0;

        diffCount.put(0, 1);

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == x) diff++;
            else if (arr[i] == y) diff--;

            result += diffCount.getOrDefault(diff, 0);

            diffCount.put(diff, diffCount.getOrDefault(diff, 0) + 1);
        }

        return result;
    }
}
```

### Code (Python)

```python
class Solution:
    def sameOccurrence(self, arr, x, y):
        diffCount = {}
        diff = 0
        result = 0

        diffCount[0] = 1

        for i in arr:
            if i == x:
                diff += 1
            elif i == y:
                diff -= 1

            result += diffCount.get(diff, 0)

            diffCount[diff] = diffCount.get(diff, 0) + 1

        return result
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
