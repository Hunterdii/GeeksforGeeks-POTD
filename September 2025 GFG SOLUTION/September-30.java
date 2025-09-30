class Solution {
    public ArrayList<String> binstr(int n) {
        ArrayList<String> res = new ArrayList<>();
        for (int i = 0; i < (1 << n); i++) {
            StringBuilder s = new StringBuilder();
            for (int j = n - 1; j >= 0; j--) s.append((i >> j & 1) == 1 ? '1' : '0');
            res.add(s.toString());
        }
        return res;
    }
}
