## 17. Count Pairs Whose Sum is Equal to X

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1)

### Problem Description

Given two linked lists `head1` and `head2` with distinct elements, determine the count of all distinct pairs from both lists whose sum is equal to the given value `x`.

Note: A valid pair would be in the form `(x, y)` where `x` is from the first linked list and `y` is from the second linked list.

**Example 1:**

Input:

```
head1 = 1->2->3->4->5->6
head2 = 11->12->13
x = 15
```

Output:

```
3
```

Explanation: There are a total of 3 pairs whose sum is 15: (4,11), (3,12), and (2,13)

**Your Task:**

You only need to implement the given function `countPairs()` that takes two linked lists `head1` and `head2` and returns the count of distinct pairs whose sum is equal to `x`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(length(head1) + length(head2)), as we traverse both linked lists once.
- **Expected Auxiliary Space Complexity:** O(length(head1)) or O(length(head2)), depending on which linked list is larger, for storing elements in the set.

### My Approach

1. **Initialization:**

   - Create two sets `set1` and `set2` to store the elements of the first and second linked lists, respectively.
   - Initialize a variable `count` to 0 to keep track of the count of pairs whose sum is equal to `x`.

2. **Populate Sets:**

   - Traverse the first linked list `head1` and insert its elements into `set1`.
   - Traverse the second linked list `head2` and insert its elements into `set2`.

3. **Count Pairs:**

   - Traverse the second linked list `head2`.
   - For each element `y` in `head2`, calculate the complement `x - y`.
   - If the complement exists in `set1`, increment the `count`.

4. **Return Count:**
   - After traversing `head2`, return the final count.

### Time and Auxiliary Space Complexity

- **Time Complexity:** O(length(head1) + length(head2)), as we traverse both linked lists once.
- **Auxiliary Space Complexity:** O(length(head1)) or O(length(head2)), depending on which set is larger.

### Code (C++)

```cpp
class Solution{
public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_set<int> set1, set2;
        int count = 0;

        // Populate set1 with the elements of the first linked list
        while (head1 != NULL) {
            set1.insert(head1->data);
            head1 = head1->next;
        }

        // Traverse the second linked list and check for complements
        while (head2 != NULL) {
            int complement = x - head2->data;
            if (set1.find(complement) != set1.end()) {
                count++;
            }
            head2 = head2->next;
        }

        return count;
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
