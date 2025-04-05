## 24. Insert an Element at the Bottom of a Stack

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1)

### Problem Description

You are given a stack `st` of \(n\) integers and an element \(x\). You have to insert \(x\) at the bottom of the given stack.

**Example:**

Input:

```
n = 5
x = 2
st = {4,3,2,1,8}
```

Output:

```
{2,4,3,2,1,8}
```

Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.

### My Approach

1. **Insertion Process:**
   - Create a temporary stack `tmp`.
   - Push all elements from the original stack `st` to the temporary stack `tmp`.
   - Push the new element \(x\) to the bottom of the stack `st`.
   - Push back all elements from the temporary stack `tmp` to the original stack `st`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where \(n\) is the number of elements in the stack.
- **Expected Auxiliary Space Complexity:** O(n), as we use a temporary stack to store the elements.

### Code (C++)

```cpp
class Solution {
public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int> tmp;

        // Push all elements from the original stack to a temporary stack
        while (!st.empty()) {
            tmp.push(st.top());
            st.pop();
        }

        // Push the new element to the bottom of the stack
        st.push(x);

        // Push back all elements from the temporary stack to the original stack
        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }

        return st;
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
