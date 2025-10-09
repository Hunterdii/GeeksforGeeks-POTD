/*
class Node {
    int data;
    Node left, right;
    Node(int val){
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    public ArrayList<Integer> postOrder(Node root) {
        ArrayList<Integer> res = new ArrayList<>();
        Node curr = root;
        while (curr != null) {
            if (curr.right == null) {
                res.add(curr.data);
                curr = curr.left;
            } else {
                Node pred = curr.right;
                while (pred.left != null && pred.left != curr) pred = pred.left;
                if (pred.left == null) {
                    res.add(curr.data);
                    pred.left = curr;
                    curr = curr.right;
                } else {
                    pred.left = null;
                    curr = curr.left;
                }
            }
        }
        Collections.reverse(res);
        return res;
    }
}
