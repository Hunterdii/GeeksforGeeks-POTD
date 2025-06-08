class Solution {
    public boolean isSumString(String s) {
        int n = s.length();
        for (int l1 = 1; l1 < n; l1++) {
            for (int l2 = 1; l1 + l2 < n; l2++) {
                if (check(s, 0, l1, l2)) return true;
            }
        }
        return false;
    }

    boolean check(String s, int i, int l1, int l2) {
        String x = s.substring(i, i + l1), y = s.substring(i + l1, i + l1 + l2);
        if ((x.length() > 1 && x.charAt(0) == '0') || (y.length() > 1 && y.charAt(0) == '0')) return false;
        String sum = add(x, y);
        int l3 = sum.length();
        if (i + l1 + l2 + l3 > s.length()) return false;
        String z = s.substring(i + l1 + l2, i + l1 + l2 + l3);
        if (!sum.equals(z)) return false;
        if (i + l1 + l2 + l3 == s.length()) return true;
        return check(s, i + l1, l2, l3);
    }

    String add(String a, String b) {
        if (a.length() < b.length()) return add(b, a);
        StringBuilder sb = new StringBuilder();
        int carry = 0, n = a.length(), m = b.length();
        for (int i = 0; i < m; i++) {
            int s = (a.charAt(n - 1 - i) - '0') + (b.charAt(m - 1 - i) - '0') + carry;
            sb.append(s % 10);
            carry = s / 10;
        }
        for (int i = m; i < n; i++) {
            int s = (a.charAt(n - 1 - i) - '0') + carry;
            sb.append(s % 10);
            carry = s / 10;
        }
        if (carry > 0) sb.append(carry);
        return sb.reverse().toString();
    }
}
