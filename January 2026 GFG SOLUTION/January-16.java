class Solution {
    public int minMen(int arr[]) {
        int n = arr.length;
        List<int[]> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                v.add(new int[]{Math.max(0, i - arr[i]), Math.min(n - 1, i + arr[i])});
            }
        }
        if (v.isEmpty()) return -1;
        v.sort((a, b) -> a[0] - b[0]);
        int cnt = 0, pos = -1, i = 0;
        while (pos < n - 1) {
            if (i >= v.size() || v.get(i)[0] > pos + 1) return -1;
            int reach = pos;
            while (i < v.size() && v.get(i)[0] <= pos + 1) reach = Math.max(reach, v.get(i++)[1]);
            cnt++;
            pos = reach;
        }
        return cnt;
    }
}
