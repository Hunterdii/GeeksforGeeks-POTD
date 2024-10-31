/*
 * Insert in Sorted way in a Sorted DLL
Difficulty: MediumAccuracy: 28.25%Submissions: 51K+Points: 4
Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

Note: The DLL is sorted in ascending order

Example:

Input: LinkedList: 3->5->8->10->12 , x = 9

Output: 3->5->8->9->10->12

Explanation: Here node 9 is inserted in the Doubly Linked-List.
Input: LinkedList: 1->4->10->11 , x = 15

Output: 1->4->10->11->15

Constraints:
1 <= number of nodes <= 103
1 <= node -> data , x <= 104
 */


 //{ Driver Code Starts


// } Driver Code Ends


/*class of the node of the DLL is as
/*
class Node {
    int data;
    Node prev, next;
    Node(int data) {
        this.data = data;
        this.prev = this.next = null;
    }
}
*/


class Solution {
    public Node sortedInsert(Node head, int x) {
        // Create a new node with the given value x
        Node newNode = new Node(x);

        // Case 1: Insert at the beginning if DLL is empty or x is smaller than head's data
        if (head == null || x < head.data) {
            newNode.next = head;
            if (head != null) {
                head.prev = newNode;
            }
            return newNode;  // New head of the DLL
        }

        // Traverse the list to find the correct insertion point
        Node current = head;
        while (current.next != null && current.next.data < x) {
            current = current.next;
        }

        // Insert newNode after 'current'
        newNode.next = current.next;
        if (current.next != null) {
            current.next.prev = newNode;
        }
        newNode.prev = current;
        current.next = newNode;

        return head;  // Return the original head
    }
}

