/*
class Node{
    int data;
    Node left, right;
    Node(int d){
        data=d;
        left=right=null;
    }
}
*/

class Solution {
    int res;
    
    int findMaxSum(Node root) {
        res = Integer.MIN_VALUE;
        dfs(root);
        return res;
    }
    
    int dfs(Node node) {
        if (node == null) return 0;
        int l = Math.max(0, dfs(node.left));
        int r = Math.max(0, dfs(node.right));
        res = Math.max(res, node.data + l + r);
        return node.data + Math.max(l, r);
    }
}
