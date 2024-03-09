public static int firstElementKTime(int n, int k, int[] a) {
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int i = 0; i < n; i++) {
            count.put(a[i], count.getOrDefault(a[i], 0) + 1);
            if (count.get(a[i]) >= k) {
                return a[i];
            }
        }
        return -1;
    } 
