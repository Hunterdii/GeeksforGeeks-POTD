class Solution {
    public ArrayList<String> findExpr(String s, int target) {
        ArrayList<String> res = new ArrayList<>();
        dfs(s, target, 0, 0, 0, "", res);
        return res;
    }
    void dfs(String s, int target, int i, long val, long prev, String path, ArrayList<String> res) {
        if (i == s.length()) {
            if (val == target) res.add(path);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (j > i && s.charAt(i) == '0') break;
            long cur = Long.parseLong(s.substring(i, j + 1));
            if (i == 0) dfs(s, target, j + 1, cur, cur, "" + cur, res);
            else {
                dfs(s, target, j + 1, val + cur, cur, path + "+" + cur, res);
                dfs(s, target, j + 1, val - cur, -cur, path + "-" + cur, res);
                dfs(s, target, j + 1, val - prev + prev * cur, prev * cur, path + "*" + cur, res);
            }
        }
    }
}
