## 10. Party of Couples

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/alone-in-couple5507/1)

### Problem Description

You are given an integer array `arr[]` of size `n`, representing `n` number of people in a party, each person is denoted by an integer. Couples are represented by the same number, i.e., two people have the same integer value, it means they are a couple. Find out the only single person in the party of couples.

**Example:**

Input:

```
n = 5
arr = {1, 2, 3, 2, 1}
```

Output:

```
3
```

Explanation: Only the number 3 is single.

Input:

```
n = 11
arr = {1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6}
```

Output:

```
4
```

Explanation: 4 is the only single.

**Your Task:**

You do not need to read input or print anything. Your task is to complete the function `findSingle()` which takes the size of the array `n` and the array `arr[]` as input parameters and returns the only single person.

**Expected Time Complexity:** O(n)
**Expected Auxiliary Space:** O(1)

**Constraints:**

- 1 ≤ n ≤ 10^4
- 1 ≤ arr[i] ≤ 10^6

### My Approach

1. **XOR Operation:**

- Initialize a variable `single` to 0.
- Traverse through the array and perform bitwise XOR operation of each element with the `single` variable.
- At the end, `single` will hold the value of the single person in the party.

2. **Return:**

- Return the value of `single`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse through the array once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution{
public:
    int findSingle(int n, int arr[]) {
        int single = 0;

        for(int i = 0; i < n; i++) {
            single ^= arr[i];
        }

        return single;
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
