class Solution {
    public int powerfulInteger(int[][] intervals, int k) {
        TreeMap<Integer, Integer> events = new TreeMap<>();
        for (int[] i : intervals) {
            events.put(i[0], events.getOrDefault(i[0], 0) + 1);
            events.put(i[1] + 1, events.getOrDefault(i[1] + 1, 0) - 1);
        }
        int count = 0, result = -1;
        for (Map.Entry<Integer, Integer> e : events.entrySet()) {
            if (e.getValue() > 0) {
                count += e.getValue();
                if (count >= k) result = e.getKey();
            } else {
                if (count >= k) result = e.getKey() - 1;
                count += e.getValue();
            }
        }
        return result;
    }
}
