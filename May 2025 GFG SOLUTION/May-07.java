class Solution {
    public static ArrayList<ArrayList<Integer>> Paths(Node root) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        if (root != null) dfs(root, new ArrayList<>(), result);
        return result;
    }
    
    private static void dfs(Node node, ArrayList<Integer> path, ArrayList<ArrayList<Integer>> result) {
        path.add(node.data);
        if (node.left == null && node.right == null) result.add(new ArrayList<>(path));
        else {
            if (node.left != null) dfs(node.left, path, result);
            if (node.right != null) dfs(node.right, path, result);
        }
        path.remove(path.size() - 1);
    }
}
