/*
class Node {
    int data;
    Node left, right;

    Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    public int getMaxSum(Node root) {
        int[] res = helper(root);
        return Math.max(res[0], res[1]);
    }
    private int[] helper(Node node) {
        if (node == null) return new int[]{0, 0};
        int[] l = helper(node.left);
        int[] r = helper(node.right);
        int inc = node.data + l[1] + r[1];
        int exc = Math.max(l[0], l[1]) + Math.max(r[0], r[1]);
        return new int[]{inc, exc};
    }
}
