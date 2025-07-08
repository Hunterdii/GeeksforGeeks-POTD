class Solution {
    public ArrayList<Integer> findGreater(int[] a) {
        HashMap<Integer, Integer> f = new HashMap<>();
        for (int x : a) f.put(x, f.getOrDefault(x, 0) + 1);
        ArrayList<Integer> r = new ArrayList<>(Collections.nCopies(a.length, -1));
        Deque<Integer> s = new ArrayDeque<>();
        for (int i = 0; i < a.length; i++) {
            while (!s.isEmpty() && f.get(a[i]) > f.get(a[s.peekLast()]))
                r.set(s.pollLast(), a[i]);
            s.add(i);
        }
        return r;
    }
}
