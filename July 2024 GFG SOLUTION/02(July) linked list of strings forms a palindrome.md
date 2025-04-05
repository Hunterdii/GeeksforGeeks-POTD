## 02. Linked List of Strings Forms a Palindrome

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1)

### Problem Description

Given a linked list with string data, check whether the combined string formed is a palindrome. If the combined string is a palindrome, return true; otherwise, return false.

**Example:**

Input:

```
List: a -> bc -> d -> dcb -> a
```

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/8cb72c70-4ba5-4a0c-a4be-2e6d747df382" alt="Image" width="270" />
</p>
Output:
```
true
```
Explanation:
The combined string "abcddcba" is a palindrome, so the function returns true.

### My Approach

1. **Initialization:**

   - Create a string `ans` to store the combined string formed from the linked list.
   - Initialize a pointer `t` to traverse the linked list.

2. **String Construction:**

   - Traverse the linked list from head to end.
   - Append the data from each node to the string `ans`.

3. **Palindrome Check:**
   - Use two pointers `i` and `j` to check the combined string for palindrome properties.
   - Compare the characters at positions `i` and `j` while moving `i` from the start and `j` from the end towards the middle.
   - If any pair of characters does not match, return false.
   - If all characters match, return true.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the total length of the combined string formed from the linked list.
- **Expected Auxiliary Space Complexity:** O(n), as we use a string to store the combined data from the linked list.

### Code (C++)

```cpp
class Solution {
public:
    bool compute(Node* head) {
        string ans = "";
        Node* t = head;
        while (t) {
            ans += t->data;
            t = t->next;
        }
        int i = 0, j = ans.size() - 1;
        while (i < j) {
            if (ans[i] != ans[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
```

### Code (Java)

```java
class Solution {
    public boolean compute(Node head) {
        StringBuilder ans = new StringBuilder();
        Node t = head;
        while (t != null) {
            ans.append(t.data);
            t = t.next;
        }
        int i = 0, j = ans.length() - 1;
        while (i < j) {
            if (ans.charAt(i) != ans.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
```

### Code (Python)

```python
def compute(head):
    ans = ""
    t = head
    while t:
        ans += t.data
        t = t.next
    i, j = 0, len(ans) - 1
    while i < j:
        if ans[i] != ans[j]:
            return False
        i += 1
        j -= 1
    return True
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
