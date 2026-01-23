class Solution {
    public int maxPeople(int[] arr) {
        int n = arr.length, res = 0;
        int[] l = new int[n], r = new int[n];
        Arrays.fill(l, 1);
        Arrays.fill(r, 1);
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && arr[s.peek()] < arr[i]) l[i] += l[s.pop()];
            s.push(i);
        }
        s.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && arr[s.peek()] < arr[i]) r[i] += r[s.pop()];
            s.push(i);
        }
        for (int i = 0; i < n; i++) res = Math.max(res, l[i] + r[i] - 1);
        return res;
    }
}
