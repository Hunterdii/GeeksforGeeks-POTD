/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    public int findMedian(Node root) {
        int n = 0, k = 0, med = -1;
        Node c = root;
        while (c != null) {
            if (c.left == null) { n++; c = c.right; }
            else {
                Node p = c.left;
                while (p.right != null && p.right != c) p = p.right;
                if (p.right == null) { p.right = c; c = c.left; }
                else { p.right = null; n++; c = c.right; }
            }
        }
        k = (n + 1) / 2;
        c = root;
        while (c != null) {
            if (c.left == null) {
                if (++med == k - 1) return c.data;
                c = c.right;
            } else {
                Node p = c.left;
                while (p.right != null && p.right != c) p = p.right;
                if (p.right == null) { p.right = c; c = c.left; }
                else {
                    p.right = null;
                    if (++med == k - 1) return c.data;
                    c = c.right;
                }
            }
        }
        return -1;
    }
}
