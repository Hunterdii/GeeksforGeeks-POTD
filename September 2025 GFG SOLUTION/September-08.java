/*
class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}
*/

class Solution {
    public Node mergeSort(Node h) {
        if (h == null || h.next == null) return h;
        Node s = h, f = h.next;
        while (f != null && f.next != null) {
            s = s.next;
            f = f.next.next;
        }
        Node r = s.next;
        s.next = null;
        return merge(mergeSort(h), mergeSort(r));
    }
    
    Node merge(Node a, Node b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.data <= b.data) {
            a.next = merge(a.next, b);
            return a;
        }
        b.next = merge(a, b.next);
        return b;
    }
}
