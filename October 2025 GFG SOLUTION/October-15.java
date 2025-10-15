/*
class Node {
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}
*/

class Solution {
    public int kthSmallest(Node root, int k) {
        Stack<Node> s = new Stack<>();
        Node n = root;
        int c = 0;
        while (n != null || !s.isEmpty()) {
            while (n != null) {
                s.push(n);
                n = n.left;
            }
            n = s.pop();
            if (++c == k) return n.data;
            n = n.right;
        }
        return -1;
    }
}
