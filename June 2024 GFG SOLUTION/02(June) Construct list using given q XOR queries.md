## 02. Construct List Using Given q XOR Queries

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1)

### Problem Description

Given a list `s` that initially contains only a single value 0, there will be `q` queries of the following types:

- `0 x`: Insert `x` into the list.
- `1 x`: For every element `a` in `s`, replace it with `a ^ x` (where `^` denotes the bitwise XOR operator).

Return the sorted list after performing the given `q` queries.

**Example:**

Input:

```
q = 5
queries[] = {{0, 6}, {0, 3}, {0, 2}, {1, 4}, {1, 5}}
```

Output:

```
1 2 3 7
```

Explanation:

```
[0] (initial value)
[0 6] (add 6 to list)
[0 6 3] (add 3 to list)
[0 6 3 2] (add 2 to list)
[4 2 7 6] (XOR each element by 4)
[1 7 2 3] (XOR each element by 5)
```

The sorted list after performing all the queries is `[1 2 3 7]`.

### My Approach

1. **Initialization:**

   - Initialize `xr` to store the cumulative XOR value.
   - Create a vector `results` to store the elements of the list.

2. **Process Queries:**

   - Iterate through the queries in reverse order.
   - If the query type is `0`, append the result of XORing the value with `xr` to the results.
   - If the query type is `1`, update `xr` by XORing it with the given value.

3. **Final Adjustments:**

   - Append the final cumulative `xr` value to the results.
   - Sort the `results` vector.

4. **Return:**
   - Return the sorted `results` vector.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(q \log q)\), due to the sorting step at the end.
- **Expected Auxiliary Space Complexity:** \(O(l)\), where \(l\) is the length of the `results` list.

### Code (C++)

```cpp
class Solution {
public:
    std::vector<int> constructList(int q, std::vector<std::vector<int>>& queries) {
        int xr = 0;
        std::vector<int> results;
        for (int i = q - 1; i >= 0; --i) {
            if (queries[i][0] == 0) {
                results.push_back(queries[i][1] ^ xr);
            } else {
                xr ^= queries[i][1];
            }
        }

        results.push_back(xr);

        std::sort(results.begin(), results.end());

        return results;
    }
};
```

### Code (Java)

```java
class Solution {
    public ArrayList<Integer> constructList(int q, int[][] queries) {
        int xr = 0;
        ArrayList<Integer> results = new ArrayList<>();
        for (int i = q - 1; i >= 0; --i) {
            if (queries[i][0] == 0) {
                results.add(queries[i][1] ^ xr);
            } else {
                xr ^= queries[i][1];
            }
        }
        results.add(xr);
        Collections.sort(results);
        return results;
    }
}
```

### Code (Python)

```python
from typing import List

class Solution:
    def constructList(self, q: int, queries: List[List[int]]) -> List[int]:
        xr = 0
        results = []
        for i in range(q - 1, -1, -1):
            if queries[i][0] == 0:
                results.append(queries[i][1] ^ xr)
            else:
                xr ^= queries[i][1]
        results.append(xr)
        results.sort()
        return results
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
