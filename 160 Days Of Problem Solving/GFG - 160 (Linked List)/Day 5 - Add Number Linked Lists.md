---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Linked-List
---

# 🚀 _Day 5. Add Number Linked Lists_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/add-two-numbers-represented-by-linked-lists)

## 💡 **Problem Description:**

You are given the head of two singly linked lists `num1` and `num2`, which represent two non-negative integers. The digits are stored in reverse order, and each node contains a single digit. Return the head of the linked list representing the sum of these two numbers.

### **Note:**

- There can be leading zeros in the input lists.
- The output list should not contain leading zeros.

## 🔍 **Example Walkthrough:**

#### **Example 1:**

Input:  
`num1 = 4 -> 5`,  
`num2 = 3 -> 4 -> 5`  
Output:  
`3 -> 9 -> 0`

![image](https://github.com/user-attachments/assets/cda1862f-a116-4e5e-bbe0-1a4826b5c9ab)

**Explanation:**  
The given numbers are `45` and `345`. Their sum is `390`.

#### **Example 2:**

Input:  
`num1 = 0 -> 0 -> 6 -> 3`,  
`num2 = 0 -> 7`  
Output:  
`7 -> 0`

![image](https://github.com/user-attachments/assets/192b5c6c-1a45-40d7-8387-bc771a9a04a4)

**Explanation:**  
The given numbers are `63` and `7`. Their sum is `70`.

### Constraints:

- 1 <= size of both linked lists <= $10^6$
- 0 <= elements of both linked lists <= 9

## 🎯 **My Approach:**

To solve this problem, we use the following steps:

1. **Reverse the Input Lists:**

   - Since the input numbers are stored in reverse order, reverse both linked lists to process them in their natural order.
   - Use a helper function `reverse()` for this purpose.

2. **Iterative Addition:**

   - Traverse both linked lists simultaneously, summing their values along with a `carry`.
   - Create new nodes for the resultant linked list using the modulus of the sum (`sum % 10`), and update the carry as `sum // 10`.

3. **Reverse the Resultant List:**

   - After adding, reverse the resultant linked list to return the result in the required format.

4. **Remove Leading Zeros:**
   - If there are any leading zeros in the resultant list (other than a single zero), remove them for a clean output.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(max(n, m)), where `n` and `m` are the lengths of the input linked lists. Each list is traversed multiple times: once for reversing and once for summing.
- **Expected Auxiliary Space Complexity:** O(1), as no extra space proportional to the size of the input is used; only a constant amount of additional space is required.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* l1, Node* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        Node* dummy = new Node(0);
        Node* tail = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) sum += l1->data, l1 = l1->next;
            if (l2) sum += l2->data, l2 = l2->next;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        Node* res = reverse(dummy->next);
        delete dummy;
        while (res && res->data == 0 && res->next) {
            Node* temp = res;
            res = res->next;
            delete temp;
        }
        return res;
    }
};
```

## Code (Java)

```java
class Solution {
    Node reverse(Node head) {
        Node prev = null, curr = head;
        while (curr != null) {
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node addTwoLists(Node l1, Node l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        Node dummy = new Node(0);
        Node tail = dummy;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int sum = carry;
            if (l1 != null) {
                sum += l1.data;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.data;
                l2 = l2.next;
            }
            carry = sum / 10;
            tail.next = new Node(sum % 10);
            tail = tail.next;
        }

        Node res = reverse(dummy.next);
        while (res != null && res.data == 0 && res.next != null) {
            res = res.next;
        }
        return res;
    }
}
```

## Code (Python)

```python
class Solution:
    def reverse(self, head):
        prev, curr = None, head
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        return prev

    def addTwoLists(self, l1, l2):
        l1 = self.reverse(l1)
        l2 = self.reverse(l2)
        dummy = Node(0)
        tail = dummy
        carry = 0

        while l1 or l2 or carry:
            summ = carry
            if l1:
                summ += l1.data
                l1 = l1.next
            if l2:
                summ += l2.data
                l2 = l2.next
            carry = summ // 10
            tail.next = Node(summ % 10)
            tail = tail.next

        res = self.reverse(dummy.next)
        while res and res.data == 0 and res.next:
            res = res.next
        return res
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
