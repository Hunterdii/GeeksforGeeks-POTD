class Solution {
    public int sumOfModes(int[] arr, int k) {
        int n = arr.length, sum = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        TreeMap<Integer, TreeSet<Integer>> buckets = new TreeMap<>();
        
        for (int i = 0; i < k; i++) freq.merge(arr[i], 1, Integer::sum);
        freq.forEach((val, f) -> buckets.computeIfAbsent(f, x -> new TreeSet<>()).add(val));
        sum += buckets.lastEntry().getValue().first();
        
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            
            TreeSet<Integer> outSet = buckets.get(freq.get(out));
            outSet.remove(out);
            if (outSet.isEmpty()) buckets.remove(freq.get(out));
            
            freq.merge(out, -1, Integer::sum);
            if (freq.get(out) > 0) 
                buckets.computeIfAbsent(freq.get(out), x -> new TreeSet<>()).add(out);
            else freq.remove(out);
            
            if (freq.containsKey(in)) {
                TreeSet<Integer> inSet = buckets.get(freq.get(in));
                inSet.remove(in);
                if (inSet.isEmpty()) buckets.remove(freq.get(in));
            }
            
            freq.merge(in, 1, Integer::sum);
            buckets.computeIfAbsent(freq.get(in), x -> new TreeSet<>()).add(in);
            sum += buckets.lastEntry().getValue().first();
        }
        return sum;
    }
}

