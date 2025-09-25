class Solution {
    public ArrayList<String> generateBinary(int n) {
        ArrayList<String> res = new ArrayList<>(n);
        for (int i = 1; i <= n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int x = i; x > 0; x /= 2) sb.append(x % 2);
            res.add(sb.reverse().toString());
        }
        return res;
    }
}
