/*
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}
*/

class Solution {
    public Node reverseKGroup(Node head, int k) {
        Node cur = head; int cnt = 0;
        while (cur != null && cnt < k) { cur = cur.next; cnt++; }
        if (cnt < k) {
            Node prev = null;
            while (head != null) {
                Node nxt = head.next; head.next = prev; prev = head; head = nxt;
            }
            return prev;
        }
        cur = reverseKGroup(cur, k);
        while (cnt-- > 0) {
            Node nxt = head.next; head.next = cur; cur = head; head = nxt;
        }
        return cur;
    }
}
