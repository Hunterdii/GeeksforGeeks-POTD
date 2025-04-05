## 01. Arrange Consonants and Vowels

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1)

### Problem Description

Given a singly linked list having \( n \) nodes containing English alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival.

**Example:**

Input:

```
n = 9
Linked List: a -> b -> c -> d -> e -> f -> g -> h -> i
```

Output:

```
a -> e -> i -> b -> c -> d -> f -> g -> h
```

Explanation:
After rearranging the input linked list according to the condition, the resultant linked list will be as shown in the output.

### My Approach

1. **Initialization:**

   - Create two dummy nodes, `dummy1` and `dummy2`, to maintain two separate lists for vowels and consonants respectively.
   - Initialize pointers `ptr1` and `ptr2` to point to the last node of the respective lists.

2. **Iterating Through the Linked List:**

   - Traverse through the given linked list.
   - If the current node contains a vowel, append it to the list of vowels, otherwise append it to the list of consonants.

3. **Adjusting Pointers:**

   - Connect the last node of the vowel list to the first node of the consonant list.
   - Set the next pointer of the last node of the consonant list to `nullptr`.

4. **Returning the New Head:**
   - Return the next node of `dummy1` as the new head of the rearranged linked list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where \( n \) is the number of nodes in the linked list.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution
{
public:
    struct Node* arrangeCV(Node *head)
    {
        Node* dummy1 = new Node(-1);
        Node* ptr1 = dummy1;
        Node* dummy2 = new Node(-1);
        Node* ptr2 = dummy2;

        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            char c = curr->data;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ptr1->next = curr;
                ptr1 = ptr1->next;
            } else {
                ptr2->next = curr;
                ptr2 = ptr2->next;
            }
        }

        ptr1->next = dummy2->next;
        ptr2->next = nullptr;

        Node* newHead = dummy1->next;
        delete dummy1;
        delete dummy2;

        return newHead;
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
