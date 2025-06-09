/*
class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
}*/

class Solution {
    boolean dfs(Node root, int l, int r) {
        if (root == null) return false;
        if (root.left == null && root.right == null && l == r) return true;
        return dfs(root.left, l, root.data - 1) || dfs(root.right, root.data + 1, r);
    }
    
    public boolean isDeadEnd(Node root) {
        return dfs(root, 1, Integer.MAX_VALUE);
    }
}
