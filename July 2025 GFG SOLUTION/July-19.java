class Solution {
    public int vowelCount(String s) {
        int[] f = new int[5];
        for (char c : s.toCharArray())
            if ("aeiou".indexOf(c) >= 0) f["aeiou".indexOf(c)]++;
        int cnt = 0, prod = 1;
        for (int x : f) if (x > 0) { prod *= x; cnt++; }
        for (int i = 2; i <= cnt; i++) prod *= i;
        return cnt == 0 ? 0 : prod;
    }
}

