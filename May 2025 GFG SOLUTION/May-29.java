/*
class Node {
    int data;
    Node left, right;

    public Node(int data){
        this.data = data;
    }
} */
class Solution {
    public int sumOfLongRootToLeafPath(Node root) {
        return dfs(root)[1];
    }

    int[] dfs(Node node) {
        if (node == null) return new int[]{0, 0};
        int[] l = dfs(node.left), r = dfs(node.right);
        if (l[0] > r[0]) return new int[]{l[0] + 1, l[1] + node.data};
        if (r[0] > l[0]) return new int[]{r[0] + 1, r[1] + node.data};
        return new int[]{l[0] + 1, Math.max(l[1], r[1]) + node.data};
    }
}
