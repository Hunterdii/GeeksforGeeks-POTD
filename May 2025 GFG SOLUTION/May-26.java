/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
} */

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
