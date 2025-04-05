# _20. Sort a K-Sorted Doubly Linked List_

### Problem Description

Given a doubly linked list where each node is at most k positions away from its correct place in the list, the task is to sort this list efficiently.

You are given a doubly linked list where the distance between a node and its target position is at most k. Sort the linked list in ascending order.

**Example:**

**Input:**
Doubly Linked List: `3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4`, k = 2

**Output:**
`1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6`

**Input:**
Doubly Linked List: `5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4`, k = 3

**Output:**
`3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7`

### My Approach

1. **Priority Queue (Min-Heap)**

   - The idea is to use a min-heap (priority queue) to keep track of the smallest element within the next `k` nodes. By popping the minimum element and adding the next element from the list, we ensure sorting within the `k` constraint.

2. **Steps**:
   - Start by adding the first `k+1` elements of the list to the min-heap.
   - Extract the minimum element from the heap to form the sorted list.
   - Continue adding the next elements from the unsorted list to the heap, maintaining `k` elements in the heap at a time.
   - Repeat this process until the entire list is sorted.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity**: O(n\*log k), where `n` is the number of nodes and `k` is the distance from the correct position. Inserting and extracting from the heap of size `k` takes `O(log k)` time, and we do this for all `n` nodes.
- **Expected Auxiliary Space Complexity**: O(k), as we only maintain a heap of size `k` at any point.

### Code (C++)

```cpp
class Compare {
  public:
    bool operator()(DLLNode *a, DLLNode *b) {
        return a->data > b->data;
    }
};

class Solution {
  public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        if (!head) return nullptr;
        priority_queue<DLLNode *, vector<DLLNode *>, Compare> pq;
        DLLNode *newHead = nullptr, *last = nullptr;
        for (int i = 0; head != nullptr && i <= k; i++) {
            pq.push(head);
            head = head->next;
        }
        while (!pq.empty()) {
            if (newHead == nullptr) {
                newHead = pq.top();
                newHead->prev = nullptr;
                last = newHead;
            } else {
                last->next = pq.top();
                pq.top()->prev = last;
                last = pq.top();
            }
            pq.pop();
            if (head != nullptr) {
                pq.push(head);
                head = head->next;
            }
        }
        last->next = nullptr;
        return newHead;
    }
};
```

### Code (Java)

```java
class Solution {
    public DLLNode sortAKSortedDLL(DLLNode head, int k) {
        if (head == null) return null;

        PriorityQueue<DLLNode> pq = new PriorityQueue<>(new Comparator<DLLNode>() {
            public int compare(DLLNode a, DLLNode b) {
                return a.data - b.data;
            }
        });

        DLLNode newHead = null, last = null;

        for (int i = 0; head != null && i <= k; i++) {
            pq.add(head);
            head = head.next;
        }

        while (!pq.isEmpty()) {
            if (newHead == null) {
                newHead = pq.poll();
                newHead.prev = null;
                last = newHead;
            } else {
                last.next = pq.poll();
                last.next.prev = last;
                last = last.next;
            }

            if (head != null) {
                pq.add(head);
                head = head.next;
            }
        }

        last.next = null;
        return newHead;
    }
}
```

### Code (Python)

```python
import heapq

class Solution:
    def sortAKSortedDLL(self, head, k):
        if not head:
            return None

        pq = []
        newHead = None
        last = None
        counter = 0

        for i in range(k + 1):
            if not head:
                break
            heapq.heappush(pq, (head.data, counter, head))
            head = head.next
            counter += 1

        while pq:
            data, _, min_node = heapq.heappop(pq)
            if not newHead:
                newHead = min_node
                newHead.prev = None
                last = newHead
            else:
                last.next = min_node
                min_node.prev = last
                last = min_node

            if head:
                heapq.heappush(pq, (head.data, counter, head))
                head = head.next
                counter += 1

        last.next = None
        return newHead
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
