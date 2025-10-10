/*
class Node {
    int data;
    Node left,right;
    Node(int d)
    {
        data=d;
        left=right=null;
    }
}
*/

class Solution {
    ArrayList<Integer> zigZagTraversal(Node root) {
        ArrayList<Integer> res = new ArrayList<>();
        if (root == null) return res;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        boolean ltr = true;
        while (!q.isEmpty()) {
            int sz = q.size();
            Integer[] lvl = new Integer[sz];
            for (int i = 0; i < sz; i++) {
                Node node = q.poll();
                int idx = ltr ? i : sz - 1 - i;
                lvl[idx] = node.data;
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            ltr = !ltr;
            Collections.addAll(res, lvl);
        }
        return res;
    }
}
