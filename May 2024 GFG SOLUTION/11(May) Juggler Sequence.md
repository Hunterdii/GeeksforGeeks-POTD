## 11. Juggler Sequence

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/juggler-sequence3930/1)

### Problem Description

Given a number \(n\), find the Juggler Sequence for this number as the first term of the sequence until it becomes 1. The Juggler Sequence is a series of integers generated using a recurrence relation.

**Example:**
Input:
```
n = 9
```
Output:
```
9 27 140 11 36 6 2 1
```
Explanation:
We start with 9 and use the Juggler Formula to generate the next terms until the sequence becomes 1.

### My Approach

1. **Initialization:**
- Create a vector `ans` to store the Juggler Sequence.
- Push the initial term \(n\) into the vector.

2. **Sequence Generation:**
- Iterate until the last term of the sequence becomes 1.
- Calculate the next term of the sequence using the Juggler Formula: 
  - If the current term is even, the next term is \(\sqrt{\text{current term}}\).
  - If the current term is odd, the next term is \(\sqrt{\text{current term}}^3\).
- Push the next term into the vector.

3. **Return:**
- Return the vector `ans` containing the Juggler Sequence.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate until the last term of the sequence becomes 1.
- **Expected Auxiliary Space Complexity:** O(n), as we use a vector to store the Juggler Sequence.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> jugglerSequence(int n) {
        vector<int> ans;
        ans.push_back(n);

        while (ans.back() > 1) {
            double sqrt_n = sqrt(ans.back());
            int next_term = (ans.back() % 2 == 0) ? static_cast<int>(sqrt_n) : static_cast<int>(pow(sqrt_n, 3));
            ans.push_back(next_term);
        }

        return ans;
    }
};
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
