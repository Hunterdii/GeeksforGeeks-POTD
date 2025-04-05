## 12. Minimum Steps to Destination

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1)

### Problem Description

Given an infinite number line where you start at 0 and can move either left or right, with the condition that in the \(i\)th move, you must take \(i\) steps. Given a destination \(d\), find the minimum number of steps required to reach that destination.

**Example:**

Input:

```
d = 10
```

Output:

```
4
```

Explanation:
The steps taken are \(+1, +2, +3,\) and \(+4\).

### My Approach

1. **Initialization:**

- Start at position 0 and initialize a variable to keep track of the sum of steps taken and another variable to keep track of the current move number.

2. **Step Calculation:**

- While the sum of steps taken is less than \(d\) or the difference between the sum and \(d\) is odd, increment the sum by the current move number and increment the move number.

3. **Return:**

- Return the current move number minus 1 as the minimum steps required to reach the destination.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(d), as the algorithm iterates up to the value of \(d\).
- **Expected Auxiliary Space Complexity:** O(1), as only a constant amount of additional space is used.

### Code (C++)

```cpp
class Solution {
public:
    int minSteps(int d) {
        if (d == 0)
            return 0;

        int sum = 0;
        int move = 1;
        while (sum < d || (sum - d) % 2 != 0) {
            sum += move;
            move++;
        }

        return move - 1;
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
