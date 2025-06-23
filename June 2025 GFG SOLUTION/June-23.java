class Solution {
    String minSum(int[] arr) {
        int[] count = new int[10];
        for (int num : arr) count[num]++;
        StringBuilder s1 = new StringBuilder(), s2 = new StringBuilder();
        boolean firstNum = true;
        for (int d = 0; d < 10; d++) {
            while (count[d]-- > 0) {
                if (firstNum) {
                    if (!(s1.length() == 0 && d == 0)) s1.append(d);
                    firstNum = false;
                } else {
                    if (!(s2.length() == 0 && d == 0)) s2.append(d);
                    firstNum = true;
                }
            }
        }
        if (s1.length() == 0) s1.append('0');
        if (s2.length() == 0) s2.append('0');
        return addString(s1.toString(), s2.toString());
    }
    String addString(String s1, String s2) {
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        StringBuilder res = new StringBuilder();
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += s1.charAt(i--) - '0';
            if (j >= 0) sum += s2.charAt(j--) - '0';
            res.append(sum % 10);
            carry = sum / 10;
        }
        while (res.length() > 1 && res.charAt(res.length() - 1) == '0')
            res.deleteCharAt(res.length() - 1);
        return res.reverse().toString();
    }
}
