class Solution {
    public String multiplyStrings(String s1, String s2) {
        boolean negative = false;
        if (s1.length() > 0 && s1.charAt(0) == '-') {
            negative = !negative;
            s1 = s1.substring(1);
        }
        if (s2.length() > 0 && s2.charAt(0) == '-') {
            negative = !negative;
            s2 = s2.substring(1);
        }
        s1 = removeLeadingZeros(s1);
        s2 = removeLeadingZeros(s2);
        if (s1.equals("0") || s2.equals("0")) return "0";
        int m = s1.length(), n = s2.length();
        int[] result = new int[m + n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (s1.charAt(i) - '0') * (s2.charAt(j) - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int num : result) {
            if (!(sb.length() == 0 && num == 0)) { 
                sb.append(num);
            }
        }
        if (negative) sb.insert(0, '-');
        return sb.toString();
    }
    private String removeLeadingZeros(String s) {
        int i = 0;
        while (i < s.length() && s.charAt(i) == '0') {
            i++;
        }
        return (i == s.length()) ? "0" : s.substring(i);
    }
}
