## 10. Nuts and Bolts Problem

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1)

### Problem Description

Given a set of `n` nuts and `n` bolts, you need to match them efficiently. Comparison between nuts to nuts or bolts to bolts is not allowed. It means a nut can only be compared with a bolt and vice versa. The elements should be ordered as: `{'!', '#', '$', '%', '&', '*', '?', '@', '^'}`.

**Example:**

Input:

```
n = 5
nuts[] = {@, %, $, #, ^}
bolts[] = {%, @, #, $ ^}
```

Output:

```
# $ % @ ^
# $ % @ ^
```

Explanation:
As per the order, `#` should come first, followed by `$`, then `%`, `@`, and `^`.

### My Approach

1. **Sorting:**

   - Sort both the `nuts` and `bolts` arrays.
   - Since the allowed characters have a fixed order, we can simply use the standard sorting algorithm.

2. **Implementation:**
   - Use the standard sorting function available in the respective language (C++, Java, Python) to sort the arrays.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n \log n)\), as we are sorting the arrays.
- **Expected Auxiliary Space Complexity:** \(O(\log n)\), due to the space complexity of the sorting algorithm used (typically quicksort).

### Code

#### C++

```cpp
class Solution {
public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        // Sort the nuts and bolts arrays
        sort(nuts, nuts + n);
        sort(bolts, bolts + n);
    }
};
```

#### Java

```java
class Solution {
    public void matchPairs(int n, char nuts[], char bolts[]) {
        // Sort the nuts and bolts arrays
        Arrays.sort(nuts);
        Arrays.sort(bolts);
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def matchPairs(self, n, nuts, bolts):
        # Sort the nuts and bolts arrays
        nuts.sort()
        bolts.sort()
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
