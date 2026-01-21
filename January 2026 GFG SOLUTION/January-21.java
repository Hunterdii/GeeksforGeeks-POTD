class Solution {
    public ArrayList<Integer> calculateSpan(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>();
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && arr[s.peek()] <= arr[i]) s.pop();
            res.add(s.isEmpty() ? i + 1 : i - s.peek());
            s.push(i);
        }
        return res;
    }
}
