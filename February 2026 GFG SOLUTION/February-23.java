class Solution {
    public static ArrayList<Integer> findUnion(int[] a, int[] b) {
        Set<Integer> set = new HashSet<>();
        for (int x : a) set.add(x);
        for (int x : b) set.add(x);
        return new ArrayList<>(set);
    }
}
