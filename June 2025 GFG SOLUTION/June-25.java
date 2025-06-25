class Solution {
    boolean sameFreq(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        Map<Integer, Integer> map = new HashMap<>();
        for (int f : freq) if (f > 0) map.put(f, map.getOrDefault(f, 0) + 1);
        if (map.size() == 1) return true;
        if (map.size() == 2) {
            Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator();
            var a = it.next(); var b = it.next();
            int f1 = a.getKey(), c1 = a.getValue(), f2 = b.getKey(), c2 = b.getValue();
            return (f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1) ||
                   (Math.abs(f1 - f2) == 1 && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)));
        }
        return false;
    }
}
