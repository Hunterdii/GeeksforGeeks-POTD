/*
class Node {
    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}*/

class Solution {
    public Node segregate(Node head) {
        if (head == null) return head;
        
        Node zero = null, one = null, two = null;
        Node zTail = null, oTail = null, tTail = null;
        
        while (head != null) {
            Node next = head.next;
            head.next = null;
            
            if (head.data == 0) {
                if (zero == null) zero = zTail = head;
                else zTail = zTail.next = head;
            } else if (head.data == 1) {
                if (one == null) one = oTail = head;
                else oTail = oTail.next = head;
            } else {
                if (two == null) two = tTail = head;
                else tTail = tTail.next = head;
            }
            head = next;
        }
        
        if (zTail != null) {
            head = zero;
            zTail.next = (one != null) ? one : two;
            if (oTail != null) oTail.next = two;
        } else if (oTail != null) {
            head = one;
            oTail.next = two;
        } else {
            head = two;
        }
        
        return head;
    }
}
