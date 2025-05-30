/*
class Node {
    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = right = null;
    }
} */
class Solution {
    public int findMaxFork(Node root, int k) {
        // code here.
        if (root == null) return -1;
        if (root.data == k) return k;
        else if (root.data < k) {
            int x = findMaxFork(root.right, k);
            if (x == -1)
                return root.data;
            else
                return x;
        }
        return findMaxFork(root.left, k);
    }
}
