# **04. Count Ways to N'th Stair (Order Does Not Matter)**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

There are `n` stairs, and a person standing at the bottom wants to reach the top. The person can climb either `1` stair or `2` stairs at a time. Count the number of ways the person can reach the top when the order of steps does not matter.

**Note:** Order does not matter means for `n = 4`: `{1, 2, 1}`, `{2, 1, 1}`, `{1, 1, 2}` are considered the same.

**Example:**

Input:

```
n = 5
```

Output:

```
3
```

Explanation: Three ways to reach the 5th stair. They are `{1, 1, 1, 1, 1}`, `{1, 1, 2, 1}` and `{1, 2, 2}`.

### My Approach

1. **Identifying the Unique Stair Combinations:**

   - Given that the order does not matter, the problem can be reduced to counting the number of unique sets of 1s and 2s that sum to `n`. Essentially, we need to find out how many different combinations of `1` and `2` can be used to form `n`.

2. **Mathematical Insight:**

   - For any number of `n`, the maximum possible number of `2`s that can be used is `n // 2`. The rest of the steps must be `1`s. Each combination of `1`s and `2`s will be unique.

3. **Dynamic Programming Approach:**

   - Since the number of ways to reach the `n`th stair depends on the number of ways to reach the previous stairs, we use dynamic programming to count these combinations.
   - We iterate from `2` to `n`, calculating the possible ways to reach each stair by combining the results from previous stairs.

4. **Optimization:**
   - As each stair's calculation only depends on the previous one, we can optimize space by using two variables to store the results of the last two computations.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as the solution boils down to counting the distinct combinations of `1`s and `2`s for the given `n`.
- **Expected Auxiliary Space Complexity:** O(n), since we only use a constant amount of additional space for computation.

### Code (C++)

```cpp
class Solution {
public:
    int nthStair(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        int prev2 = 1;
        int prev1 = 1;
        int current = 1;
        for (int i = 2; i <= n; i++) {
            current = prev2 + 1;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};
```

### Code (Java)

```java
class Solution {
    public long nthStair(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        long prev2 = 1;
        long prev1 = 1;
        long current = 1;

        for (int i = 2; i <= n; i++) {
            current = prev2 + 1;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
}
```

### Code (Python)

```python
class Solution:
    def nthStair(self, n):
        if n == 0:
            return 1
        if n == 1:
            return 1

        prev2 = 1
        prev1 = 1
        current = 1

        for i in range(2, n + 1):
            current = prev2 + 1
            prev2 = prev1
            prev1 = current

        return current
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
