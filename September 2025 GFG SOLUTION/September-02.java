/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

class Solution {
    public Node swapKth(Node head, int k) {
        if (head == null) return head;
        int n = 0;
        for (Node t = head; t != null; t = t.next) n++;
        if (k > n || 2 * k - 1 == n) return head;
        
        Node x = head, y = head, px = null, py = null;
        for (int i = 1; i < k; i++) { px = x; x = x.next; }
        for (int i = 1; i < n - k + 1; i++) { py = y; y = y.next; }
        
        if (px != null) px.next = y; else head = y;
        if (py != null) py.next = x; else head = x;
        
        Node temp = x.next;
        x.next = y.next;
        y.next = temp;
        
        return head;
    }
}
