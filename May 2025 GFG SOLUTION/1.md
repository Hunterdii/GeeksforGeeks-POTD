# *26. Insert in Sorted Circular Linked List*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1)


## **🧩 Problem Description**

Given a sorted circular linked list, insert a new node containing a given `data` value into the list so that it remains a sorted circular linked list.

## **📘 Examples**

### **Example 1:**

#### **Input:**

`head = 1→2→4 (circular)`, `data = 2`

#### **Output:**

`1→2→2→4 (circular)`

#### **Explanation:**

We insert the new node with `2` after the second node.

![image](https://github.com/user-attachments/assets/1a920fe0-45af-424f-b383-4681e617ed65)

### **Example 2:**

#### **Input:**

`head = 1→4→7→9 (circular)`, `data = 5`

#### **Output:**

`1→4→5→7→9 (circular)`

#### **Explanation:**

We insert the new node with `5` after the node containing `4`.


![image](https://github.com/user-attachments/assets/573cdaf1-4bcd-45f2-a190-0f92a87122c4)

## **🔒 Constraints**

* $`2 ≤ number of nodes ≤ 10^6`$
* $`0 ≤ node->data ≤ 10^6`$
* $`0 ≤ data ≤ 10^6`$

## **✅ My Approach**

### **Gap Detection**

We traverse the circular list looking for the proper "gap" between two consecutive nodes where the new data fits, taking into account the wrap‑around point (largest to smallest).

### **Algorithm Steps:**

1. Create the new node `n` with `n->data = data`.
2. If `head` is `null`, make `n->next = n` and return `n`.
3. Use pointer `cur = head`.
4. Loop indefinitely:

   * Let `nxt = cur->next`.
   * **Case 1:** Normal gap: if `cur->data ≤ data ≤ nxt->data`, insert between `cur` and `nxt`.
   * **Case 2:** Wrap‑around gap: if `cur->data > nxt->data` (largest→smallest transition) and `(data ≥ cur->data or data ≤ nxt->data)`, insert here.
   * **Case 3:** Full cycle fallback: if `nxt == head`, insert here.
   * On insertion: set `cur->next = n`, `n->next = nxt`.
   * If `data < head->data`, update `head = n` to maintain head as smallest.
   * Break the loop.
5. Return `head`.

## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), as in the worst case we traverse all nodes once to find the insertion point.
* **Expected Auxiliary Space Complexity:** O(1), since we use only a fixed number of pointers.

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if (!head) {
            n->next = n;
            return n;
        }
        Node* cur = head;
        while (true) {
            Node* nxt = cur->next;
            if ((cur->data <= data && data <= nxt->data) ||
                (cur->data > nxt->data && (data >= cur->data || data <= nxt->data)) ||
                nxt == head) {
                cur->next = n;
                n->next = nxt;
                if (data < head->data) head = n;
                break;
            }
            cur = nxt;
        }
        return head;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>



## 📊 **2️⃣ Linear Traversal with Do‑While Loop**

### **Algorithm Steps:**

1. Create new node `n`.
2. If `head` is `null`, link `n` to itself and return.
3. Set `cur = head`.
4. **do-while** loop until `cur` returns to `head`:

   * Let `nxt = cur->next`.
   * If `(cur->data ≤ data ≤ nxt->data)` **or** at wrap‑point `(cur->data > nxt->data and (data ≥ cur->data or data ≤ nxt->data))`, do:

     * `cur->next = n; n->next = nxt;`
     * If `data < head->data` then `head = n`.
     * Break.
   * `cur = nxt`.
5. Return `head`.

```cpp
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if (!head) {
            n->next = n;
            return n;
        }
        Node* cur = head;
        do {
            Node* nxt = cur->next;
            if ((cur->data <= data && data <= nxt->data) ||
                (cur->data > nxt->data && (data >= cur->data || data <= nxt->data))) {
                cur->next = n;
                n->next = nxt;
                if (data < head->data) head = n;
                break;
            }
            cur = nxt;
        } while (cur != head);
        return head;
    }
};
```

### ✅ **Why This Approach?**

* Uses a clear `do-while` to guarantee at least one full cycle.
* Cleaner separation of traversal and insertion logic.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(n) — one cycle maximum.
* **Space:** 🟢 O(1).

## 🪜 **3️⃣ Find Maximum Node Then Insert**

### **Algorithm Steps:**

1. Traverse to find `maxNode` where `maxNode->next == head` or data decreases.
2. Start from `maxNode->next` (smallest), traverse until correct insert point `(cur->data ≤ data ≤ cur->next->data)`.
3. If none found by `maxNode`, insert after `maxNode`.
4. Link new node and update `head` if needed.

```cpp
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if (!head) { n->next = n; return n; }
        Node* maxNode = head;
        while (maxNode->next != head && maxNode->data <= maxNode->next->data)
            maxNode = maxNode->next;
        Node* cur = maxNode->next;
        while (cur != maxNode && !(cur->data <= data && data <= cur->next->data))
            cur = cur->next;
        if (cur == maxNode && !(cur->data <= data && data <= cur->next->data))
            cur = maxNode;
        n->next = cur->next;
        cur->next = n;
        if (data < head->data) head = n;
        return head;
    }
};
```

### ✅ **Why This Approach?**

* Explicitly handles the rotation point.
* Two-phase traversal: find boundary then insert.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(n).
* **Space:** 🟢 O(1).

## 🔃 **4️⃣ Break, Insert, Reconnect**

### **Algorithm Steps:**

1. Find `tail` node (where `tail->next == head`) and break the cycle (`tail->next = nullptr`).
2. Perform standard sorted insert on linear list.
3. Reconnect `tail` to the new head to restore circularity.
4. Return the new head.

```cpp
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* n = new Node(data);
        if (!head) { n->next = n; return n; }
        Node* tail = head;
        while (tail->next != head) tail = tail->next;
        tail->next = nullptr;

        if (data < head->data) {
            n->next = head;
            head = n;
        } else {
            Node* cur = head;
            while (cur->next && cur->next->data < data) cur = cur->next;
            n->next = cur->next;
            cur->next = n;
        }

        tail = head;
        while (tail->next) tail = tail->next;
        tail->next = head;
        return head;
    }
};
```

### ✅ **Why This Works:**

* Leverages familiar linear list insert.
* Easy to debug by isolating circular logic.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(n).
* **Space:** 🟢 O(1).

## 🆚 **Comparison of Approaches**

| **Approach**                  | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                                  | ⚠️ **Cons**                    |
| ----------------------------- | ----------- | ------------- | ------------------------------------------- | ------------------------------ |
| ▶️ Gap Detection (main)       | 🟢 O(n)     | 🟢 O(1)       | Elegant, single pass handles all edge cases | Condition‑heavy logic          |
| 🔁 Do‑While Traversal         | 🔸 O(n)     | 🟢 O(1)       | Guaranteed cycle, clear syntax              | Slightly more verbose          |
| 🪜 Max Node First             | 🔸 O(n)     | 🟢 O(1)       | Separates boundary detection from insertion | Two traversal phases           |
| 🔃 Break → Insert → Reconnect | 🔸 O(n)     | 🟢 O(1)       | Simplifies to linear insert + reconnect     | Modifies structure temporarily |

### ✅ **Best Choice by Scenario**

| **Scenario**                                 | **Recommended Approach**      |
| -------------------------------------------- | ----------------------------- |
| 🔁 Want concise, all‑in‑one detection/insert | 🥇 Gap Detection              |
| 🔧 Prefer explicit loop control              | 🥈 Do‑While Traversal         |
| 🧪 Need clear boundary then insertion logic  | 🥉 Max Node First             |
| 🪛 Familiar with linear inserts              | 🔹 Break → Insert → Reconnect |

</details>



## **🧑‍💻 Code (Java)**

```java
class Solution {
    public Node sortedInsert(Node head, int data) {
        Node n = new Node(data);
        if (head == null) {
            n.next = n;
            return n;
        }
        Node cur = head;
        while (true) {
            if ((cur.data <= data && cur.next.data >= data) ||
                (cur.data > cur.next.data && (data >= cur.data || data <= cur.next.data)) ||
                cur.next == head) {
                n.next = cur.next;
                cur.next = n;
                if (data < head.data) head = n;
                break;
            }
            cur = cur.next;
        }
        return head;
    }
}
```


## **🐍 Code (Python)**

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
     

class Solution:
    def sortedInsert(self, head, data):
        n = Node(data)
        if not head:
            n.next = n
            return n
        cur = head
        while True:
            if (cur.data <= data <= cur.next.data or
                cur.data > cur.next.data and (data >= cur.data or data <= cur.next.data) or
                cur.next == head):
                n.next = cur.next
                cur.next = n
                if data < head.data:
                    head = n
                break
            cur = cur.next
        return head
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
