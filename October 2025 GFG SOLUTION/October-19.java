/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    public ArrayList<Integer> getKClosest(Node root, int target, int k) {
        ArrayList<Integer> in = new ArrayList<>();
        Stack<Node> s = new Stack<>();
        Node curr = root;
        while (curr != null || !s.isEmpty()) {
            while (curr != null) {
                s.push(curr);
                curr = curr.left;
            }
            curr = s.pop();
            in.add(curr.data);
            curr = curr.right;
        }
        int n = in.size(), l = 0, r = n - 1, pos = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (in.get(m) <= target) {
                pos = m;
                l = m + 1;
            } else r = m - 1;
        }
        ArrayList<Integer> res = new ArrayList<>();
        l = pos; r = pos + 1;
        while (k-- > 0) {
            if (r >= n || (l >= 0 && Math.abs(in.get(l) - target) <= Math.abs(in.get(r) - target)))
                res.add(in.get(l--));
            else
                res.add(in.get(r++));
        }
        return res;
    }
}
