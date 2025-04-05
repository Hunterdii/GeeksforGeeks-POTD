# _26. Roof Top_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/roof-top-1587115621/1)

### Problem Description

You are given the heights of consecutive buildings. You can move from the roof of a building to the roof of the next adjacent building. You need to find the maximum number of consecutive steps you can take such that you gain an increase in altitude with each step.

_Examples:_

Input: `arr[] = [1, 2, 2, 3, 2]`  
Output: `1`  
Explanation: `1, 2` or `2, 3` are the only consecutive buildings with increasing heights, thus the maximum number of consecutive steps with an increase in altitude would be `1` in both cases.

Input: `arr[] = [1, 2, 3, 4]`  
Output: `3`  
Explanation: `1 to 2 to 3 to 4` is the jump of length `3` to have the maximum number of buildings with increasing heights, so the maximum steps with increasing altitude becomes `3`.

### My Approach

1. _Iterate through the array:_

   - Maintain two variables: one for the current count of consecutive increasing steps (`c`) and another for the maximum count found so far (`m`).

2. _Condition Check:_

   - For each building, compare its height with the previous building. If the current building is taller, increment the count (`c`). If not, compare and update the maximum count (`m`) and reset `c`.

3. _Final Answer:_
   - After traversing the array, the maximum count (`m`) will give the maximum number of consecutive steps with increasing altitude.

### Time and Auxiliary Space Complexity

- _Expected Time Complexity:_ O(n), where n is the length of the array, as we perform a single pass through the array.
- _Expected Auxiliary Space Complexity:_ O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int maxStep(vector<int>& arr) {
        int c = 0, m = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1])
                ++c;
            else {
                m = max(m, c);
                c = 0;
            }
        }
        return max(m, c);
    }
};
```

### Code (Java)

```java
class Solution {
    public int maxStep(int arr[]) {
        int c = 0, m = 0;
        for (int i = 1; i < arr.length; ++i) {
            if (arr[i] > arr[i - 1]) {
                ++c;
            } else {
                m = Math.max(m, c);
                c = 0;
            }
        }
        return Math.max(m, c);
    }
}
```

### Code (Python)

```python
class Solution:
    def maxStep(self, arr):
        c = 0
        m = 0
        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                c += 1
            else:
                m = max(m, c)
                c = 0
        return max(m, c)
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
