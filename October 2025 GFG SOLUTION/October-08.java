/*
class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    int idx = 0;
    public Node constructTree(int[] pre, int[] post) {
        return build(pre, post, 0, post.length - 1);
    }
    
    Node build(int[] pre, int[] post, int l, int r) {
        Node root = new Node(pre[idx++]);
        if (l != r && idx < pre.length) {
            int pos = l;
            while (post[pos] != pre[idx]) pos++;
            root.left = build(pre, post, l, pos);
            root.right = build(pre, post, pos + 1, r - 1);
        }
        return root;
    }
}
