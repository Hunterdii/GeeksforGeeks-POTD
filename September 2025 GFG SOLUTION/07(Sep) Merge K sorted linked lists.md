---
title: "🔗 Merge K Sorted Linked Lists | GFG Solution 🚀"
keywords🏷️: ["🔗 linked lists", "🏷️ merge", "📊 min heap", "📈 priority queue", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to merge K sorted linked lists: combine multiple sorted linked lists into one using min heap and divide & conquer approaches. 🚀"
date: 📅 2025-09-07
---

# *07. Merge K Sorted Linked Lists*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1)

## **🧩 Problem Description**

You are given an array `arr[]` of `n` sorted linked lists of different sizes. Your task is to **merge all these lists** into a **single sorted linked list** and return the head of the merged list.

Each linked list is already sorted in ascending order. The goal is to efficiently combine them while maintaining the sorted order of elements.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [[1, 3, 7], [2, 4, 8], [9]]
Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
Explanation: The arr[] has 3 sorted linked lists of size 3, 3, 1.
1st list: 1 -> 3 -> 7
2nd list: 2 -> 4 -> 8
3rd list: 9
The merged list will be: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
```

### Example 2

```cpp
Input: arr[] = [[1, 3], [8], [4, 5, 6]]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation: The arr[] has 3 sorted linked lists of size 2, 1, 3.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be: 1 -> 3 -> 4 -> 5 -> 6 -> 8
```

## **🔒 Constraints**

* $1 \le \text{total no. of nodes} \le 10^5$
* $1 \le \text{node->data} \le 10^3$

## **✅ My Approach**

The optimal approach uses a **Min Heap (Priority Queue)** to efficiently merge k sorted linked lists by always selecting the smallest element among the current heads of all lists:

### **Min Heap + Priority Queue**

1. **Initialize Min Heap:**
   * Create a min heap (priority queue) that orders nodes by their data values.
   * Add the head nodes of all non-empty linked lists to the heap.

2. **Build Result List:**
   * Create a dummy node to simplify list construction.
   * Use a tail pointer to track the end of the result list.

3. **Extract and Process:**
   * While heap is not empty:
     - Extract the node with minimum value from heap.
     - Append it to the result list.
     - If the extracted node has a next node, add it to the heap.

4. **Continue Until Complete:**
   * Repeat until all nodes are processed and heap becomes empty.
   * Return the head of the merged list (dummy.next).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log k), where n is the total number of nodes across all lists and k is the number of linked lists. Each node is inserted and extracted from the heap once, and heap operations take O(log k) time.
* **Expected Auxiliary Space Complexity:** O(k), where k is the number of linked lists. The heap stores at most k nodes at any time (one from each list).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        auto cmp = [](Node* a, Node* b) { return a->data > b->data; };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        
        for (Node* head : arr) if (head) pq.push(head);
        
        Node dummy(-1), *tail = &dummy;
        while (!pq.empty()) {
            Node* node = pq.top(); pq.pop();
            tail->next = node; tail = node;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Divide and Conquer Approach**

### 💡 Algorithm Steps:

1. **Pair-wise Merging:** Recursively merge pairs of lists until only one remains.
2. **Binary Division:** Use binary division to split the array of lists into halves.
3. **Two List Merge:** Implement a helper function to merge two sorted lists.
4. **Bottom-up Construction:** Continue merging until all lists are combined into a single sorted list.

```cpp
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        if (arr.empty()) return nullptr;
        while (arr.size() > 1) {
            vector<Node*> temp;
            for (int i = 0; i < arr.size(); i += 2) {
                Node* l1 = arr[i];
                Node* l2 = (i + 1 < arr.size()) ? arr[i + 1] : nullptr;
                temp.push_back(merge2Lists(l1, l2));
            }
            arr = temp;
        }
        return arr[0];
    }
    
private:
    Node* merge2Lists(Node* l1, Node* l2) {
        Node dummy(-1), *tail = &dummy;
        while (l1 && l2) {
            if (l1->data <= l2->data) {
                tail->next = l1; l1 = l1->next;
            } else {
                tail->next = l2; l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k) - Each node is visited log k times where k is number of lists
* **Auxiliary Space:** 💾 O(log k) - Recursion stack space for divide and conquer

### ✅ **Why This Approach?**

* Optimal space complexity with minimal recursion overhead
* Better cache locality compared to heap approach
* Classic divide and conquer pattern, easier to understand

## 📊 **3️⃣ Flatten and Sort Approach**

### 💡 Algorithm Steps:

1. **Collect All Values:** Traverse all lists and store all node values in a vector.
2. **Sort Values:** Use built-in sort function to sort the collected values.
3. **Reconstruct List:** Create a new linked list using the sorted values.
4. **Return Result:** Return the head of the newly created sorted list.

```cpp
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        vector<int> values;
        for (Node* head : arr) {
            while (head) {
                values.push_back(head->data);
                head = head->next;
            }
        }
        sort(values.begin(), values.end());
        
        Node dummy(-1), *tail = &dummy;
        for (int val : values) {
            tail->next = new Node(val);
            tail = tail->next;
        }
        return dummy.next;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates the time complexity
* **Auxiliary Space:** 💾 O(n) - Extra space for storing all values

### ✅ **Why This Approach?**

* Simple and straightforward implementation
* Good when memory is not a primary constraint
* Leverages highly optimized sorting algorithms

## 📊 **4️⃣ Sequential Merge Approach**

### 💡 Algorithm Steps:

1. **Initialize Result:** Start with the first list as the result.
2. **Sequential Merging:** Merge each subsequent list with the current result.
3. **Two-Pointer Merge:** Use standard two-pointer technique for merging two sorted lists.
4. **Continue Until Complete:** Process all lists sequentially.

```cpp
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        if (arr.empty()) return nullptr;
        Node* result = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            result = merge2Lists(result, arr[i]);
        }
        return result;
    }
    
private:
    Node* merge2Lists(Node* l1, Node* l2) {
        Node dummy(-1), *tail = &dummy;
        while (l1 && l2) {
            if (l1->data <= l2->data) {
                tail->next = l1; l1 = l1->next;
            } else {
                tail->next = l2; l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × k) - Each merge operation takes O(n) and we do k-1 merges
* **Auxiliary Space:** 💾 O(1) - Only using constant extra space

### ✅ **Why This Approach?**

* Minimal space complexity
* Easy to implement and understand
* Good for small number of lists

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Min Heap**                   | 🟢 O(n log k)          | 🟡 O(k)                 | 🚀 Optimal for many lists        | 💾 Extra heap space                  |
| 🔍 **Divide & Conquer**           | 🟢 O(n log k)          | 🟢 O(log k)             | 📖 Optimal time & space          | 🔧 Complex recursion logic           |
| 🔄 **Flatten & Sort**             | 🟡 O(n log n)          | 🟡 O(n)                 | ⭐ Easy to understand            | 💾 Extra space, slower for large k   |
| 📝 **Sequential Merge**           | 🔴 O(n × k)            | 🟢 O(1)                 | 💾 Minimal space usage          | ⏱️ Inefficient for many lists        |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Many lists (k > 100)**                      | 🥇 **Min Heap**                      | ★★★★★                     |
| 📖 **Optimal performance**                        | 🥈 **Divide & Conquer**              | ★★★★★                     |
| 💾 **Memory constrained**                         | 🥉 **Sequential Merge**              | ★★★☆☆                     |
| 🎯 **Simple implementation**                      | 🏅 **Flatten & Sort**                | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    Node mergeKLists(Node[] arr) {
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.data - b.data);
        for (Node head : arr) if (head != null) pq.offer(head);
        
        Node dummy = new Node(-1), tail = dummy;
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            tail.next = node; tail = node;
            if (node.next != null) pq.offer(node.next);
        }
        return dummy.next;
    }
}
```

## **🐍 Code (Python)**

```python
import heapq

class Solution:
    def mergeKLists(self, arr):
        heap = []
        for i, head in enumerate(arr):
            if head: heapq.heappush(heap, (head.data, i, head))
        
        dummy = Node(-1)
        tail = dummy
        while heap:
            _, i, node = heapq.heappop(heap)
            tail.next = node
            tail = node
            if node.next: heapq.heappush(heap, (node.next.data, i, node.next))
        return dummy.next
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
