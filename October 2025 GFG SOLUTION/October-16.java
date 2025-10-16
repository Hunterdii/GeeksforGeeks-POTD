/*
class Node {
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
*/

class Solution {
    Node removekeys(Node root, int l, int r) {
        if (root == null) return null;
        root.left = removekeys(root.left, l, r);
        root.right = removekeys(root.right, l, r);
        if (root.data < l) return root.right;
        if (root.data > r) return root.left;
        return root;
    }
}
