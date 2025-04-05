# _03. Majority Vote_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/majority-vote/1)

### Problem Description

You are given an array of integers, `nums[]`, where each number represents a vote for a candidate. Return the candidates that have votes greater than one-third of the total votes. If there’s no majority vote, return -1.

_Example:_

Input:

```plaintext
nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
```

Output:

```plaintext
[5, 6]
```

Explanation: 5 and 6 occur more than n/3 times.

Input:

```plaintext
nums = [1, 2, 3, 4, 5]
```

Output:

```plaintext
[-1]
```

Explanation: No candidate occurs more than n/3 times.

### My Approach

1. _Candidate Selection:_
   - Use the Boyer-Moore Voting Algorithm to identify potential candidates that could be a majority, tracking two candidates and their counts.
2. _Validation:_

   - After identifying candidates, validate their counts in the original array to check if they occur more than n/3 times.

3. _Result Compilation:_
   - Store candidates that meet the criteria and return them; if none meet the criteria, return -1.

### Time and Auxiliary Space Complexity

- _Expected Time Complexity:_ O(n), as we traverse the array a constant number of times to find and validate candidates.
- _Expected Auxiliary Space Complexity:_ O(1), as we use a constant amount of additional space to store candidate information.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> findMajority(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {-1};

        int num1 = -1, num2 = -1;
        int c1 = 0, c2 = 0;

        for (auto x : nums) {
            if (x == num1) {
                c1++;
            } else if (x == num2) {
                c2++;
            } else if (c1 == 0) {
                num1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                num2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = 0, c2 = 0;
        for (auto x : nums) {
            if (x == num1) c1++;
            else if (x == num2) c2++;
        }

        vector<int> res;
        if (c1 > n / 3) res.push_back(num1);
        if (c2 > n / 3) res.push_back(num2);

        if (res.empty()) res.push_back(-1);

        return res;
    }
};
```

### Code (Java)

```java
class Solution {
    public List<Integer> findMajority(List<Integer> nums) {
        int n = nums.size();
        List<Integer> res = new ArrayList<>();

        if (n == 0) return Arrays.asList(-1);

        int num1 = -1, num2 = -1, c1 = 0, c2 = 0;

        for (int x : nums) {
            if (x == num1) {
                c1++;
            } else if (x == num2) {
                c2++;
            } else if (c1 == 0) {
                num1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                num2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = 0;
        c2 = 0;
        for (int x : nums) {
            if (x == num1) c1++;
            else if (x == num2) c2++;
        }

        if (c1 > n / 3) res.add(num1);
        if (c2 > n / 3) res.add(num2);

        if (res.isEmpty()) res.add(-1);

        return res;
    }
}
```

### Code (Python)

```python
class Solution:
    def findMajority(self, nums):
        n = len(nums)
        if n == 0:
            return [-1]

        num1, num2 = -1, -1
        c1, c2 = 0, 0

        for x in nums:
            if x == num1:
                c1 += 1
            elif x == num2:
                c2 += 1
            elif c1 == 0:
                num1 = x
                c1 = 1
            elif c2 == 0:
                num2 = x
                c2 = 1
            else:
                c1 -= 1
                c2 -= 1

        c1, c2 = 0, 0
        for x in nums:
            if x == num1:
                c1 += 1
            elif x == num2:
                c2 += 1

        res = []
        if c1 > n // 3:
            res.append(num1)
        if c2 > n // 3:
            res.append(num2)

        if not res:
            res.append(-1)

        return res
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
