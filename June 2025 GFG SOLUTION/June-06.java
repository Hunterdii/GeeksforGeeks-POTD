class Solution {
    ArrayList<Integer> search(String pat, String txt) {
        int d = 256, q = 101, m = pat.length(), n = txt.length();
        int ph = 0, th = 0, h = 1;
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < m - 1; i++) h = (h * d) % q;
        for (int i = 0; i < m; i++) {
            ph = (d * ph + pat.charAt(i)) % q;
            th = (d * th + txt.charAt(i)) % q;
        }
        for (int i = 0; i <= n - m; i++) {
            if (ph == th) {
                boolean match = true;
                for (int j = 0; j < m; j++) {
                    if (txt.charAt(i + j) != pat.charAt(j)) {
                        match = false;
                        break;
                    }
                }
                if (match) res.add(i + 1);
            }
            if (i < n - m) {
                th = (d * (th - txt.charAt(i) * h) + txt.charAt(i + m)) % q;
                if (th < 0) th += q;
            }
        }
        return res;
    }
}
