class Solution {
    int max_level = 0;
    void leftViewUtil(ArrayList<Integer> result, Node root, int level) {
        if (root == null) return;
        if (max_level < level) {
            result.add(root.data);
            max_level = level;
        }

        leftViewUtil(result, root.left, level + 1);
        leftViewUtil(result, root.right, level + 1);
    }

    ArrayList<Integer> leftView(Node root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        leftViewUtil(result, root, 1);
        return result;
    }
}
