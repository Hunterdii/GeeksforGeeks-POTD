class Solution {
    public ArrayList<Integer> asciirange(String s) {
        ArrayList<Integer> result = new ArrayList<>();
        int n = s.length();
        for (int i = 0; i < 26; i++) {
            int first = -1, last = -1;
            for (int j = 0; j < n; j++) {
                if (s.charAt(j) - 'a' == i) {
                    if (first == -1) first = j;
                    last = j;
                }
            }
            if (first != -1 && last > first) {
                int sum = 0;
                for (int k = first + 1; k < last; k++)
                    sum += s.charAt(k);
                if (sum != 0) result.add(sum);
            }
        }
        return result;
    }
}
