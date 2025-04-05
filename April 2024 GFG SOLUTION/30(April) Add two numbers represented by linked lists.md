## 30. Add Two Numbers Represented by Linked Lists

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1)

### Problem Description

Given two decimal numbers, num1 and num2, represented by linked lists of size n and m respectively, the task is to return a linked list that represents the sum of these two numbers.

**Example:**

Input:

```
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
```

Output:

```
3->9->0->null
```

Explanation:
For the given two linked lists (4 5) and (3 4 5), after adding the two linked lists, the resultant linked list will be (3 9 0).

### My Approach

1. **Reverse the Lists:**

   - Reverse both input linked lists to make it easier to add the numbers from the least significant digit.

2. **Addition:**

   - Iterate through both lists simultaneously, adding corresponding digits along with any carry from the previous addition.
   - Create a new linked list to store the result.

3. **Handle Leading Zeros:**

   - While adding digits, handle the case where one number has more digits than the other.
   - Handle any carry left after the addition.

4. **Reverse Result:**

   - Reverse the resulting linked list to obtain the final sum.

5. **Return Result:**
   - Return the head of the resulting linked list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + m), where n and m are the sizes of the input linked lists.
- **Expected Auxiliary Space Complexity:** O(max(n, m)), for the resultant linked list.

### Code (C++)

```cpp
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node *sum = NULL;
        int carry = 0;

        while (num1 != NULL || num2 != NULL || carry != 0)
        {
            int newVal = carry;

            if (num1)
                newVal += num1->data;
            if (num2)
                newVal += num2->data;

            carry = newVal / 10;
            newVal = newVal % 10;

            Node *newNode = new Node(newVal);
            newNode->next = sum;
            sum = newNode;

            if (num1)
                num1 = num1->next;
            if (num2)
                num2 = num2->next;
        }

        while (sum != NULL && sum->data == 0)
        {
            Node *temp = sum->next;
            sum->next = NULL;
            delete (sum);
            sum = temp;
        }

        if (sum == NULL)
            return new Node(0);
        return sum;
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
