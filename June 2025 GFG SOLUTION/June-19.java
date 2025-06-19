class Solution {
    public static String caseSort(String s) {
        int[] l = new int[26], u = new int[26];
        char[] c = s.toCharArray();
        for (char ch : c) {
            if (ch >= 'a') l[ch - 97]++;
            else u[ch - 65]++;
        }
        int i = 0, j = 0;
        for (int k = 0; k < c.length; k++) {
            if (c[k] >= 'a') {
                while (l[i] == 0) i++;
                c[k] = (char)(i + 97);
                l[i]--;
            } else {
                while (u[j] == 0) j++;
                c[k] = (char)(j + 65);
                u[j]--;
            }
        }
        return new String(c);
    }
}
