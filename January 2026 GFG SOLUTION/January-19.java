class Solution {
    public String removeKdig(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            while (sb.length() > 0 && k > 0 && sb.charAt(sb.length() - 1) > c) {
                sb.deleteCharAt(sb.length() - 1);
                k--;
            }
            if (sb.length() > 0 || c != '0') sb.append(c);
        }
        while (sb.length() > 0 && k-- > 0) sb.deleteCharAt(sb.length() - 1);
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
