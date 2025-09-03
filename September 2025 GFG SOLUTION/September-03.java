/*
class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
*/

class Solution {
    public Node reverse(Node head) {
        if (head == null || head.next == null) return head;
        Node curr = head, temp;
        while (curr != null) {
            temp = curr.next;
            curr.next = curr.prev;
            curr.prev = temp;
            if (temp == null) return curr;
            curr = temp;
        }
        return head;
    }
}
