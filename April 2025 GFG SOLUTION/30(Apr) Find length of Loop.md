# *30. Find Length of Loop*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-length-of-loop/1)


## **🧩 Problem Description**

Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop; otherwise, return `0`.


## **📘 Examples**

### **Example 1:**

#### **Input:**
`head = 1 → 2 → 3 → 4 → 5`, `c = 2`

#### **Output:**
`4`

#### **Explanation:**
The loop is: `3 → 4 → 5 → 2`. So, the loop length is `4`.


### **Example 2:**

#### **Input:**
`head = 25 → 14 → 19 → 33 → 10 → 21 → 39 → 90 → 58 → 45`, `c = 4`

#### **Output:**
`7`

#### **Explanation:**
The last node (45) connects to the 4th node (33), forming the loop: `33 → 10 → 21 → 39 → 90 → 58 → 45`, so the loop length is `7`.


### **Example 3:**

#### **Input:**
`head = 0 → 1 → 2 → 3`, `c = 0`

#### **Output:**
`0`

#### **Explanation:**
There is no loop in the linked list.


## **🔒 Constraints**

- $1 \leq \text{Number of nodes} \leq 10^6$
- $0 \leq \text{node.data} \leq 10^6$
- $0 \leq c \leq n - 1$


## **✅ My Approach:**

### **Floyd's Cycle Detection Algorithm (Tortoise and Hare)**

This method uses two pointers moving at different speeds. If they meet, a loop exists. Then, we count the length of the cycle.


### **🔍 Algorithm Steps:**

1. Initialize two pointers `slow` and `fast` to the head.
2. Move `slow` by one step and `fast` by two steps.
3. If they ever meet, a loop exists.
4. From the meeting point, keep moving one pointer and count the steps until it returns to the same point. This gives the loop's length.
5. If no meeting point is found, return `0`.


## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), where `N` is the number of nodes in the list, due to the full scan in the worst case.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant number of pointers.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                int c = 1;
                while ((fast = fast->next) != slow) c++;
                return c;
            }
        }
        return 0;
    }
};
```


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int countNodesinLoop(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                int c = 1;
                while ((fast = fast.next) != slow) c++;
                return c;
            }
        }
        return 0;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def countNodesInLoop(self, head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                c = 1
                while (fast := fast.next) != slow:
                    c += 1
                return c
        return 0
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
