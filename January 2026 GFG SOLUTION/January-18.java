class Solution {
    public ArrayList<Integer> nextFreqGreater(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int x : arr) freq.put(x, freq.getOrDefault(x, 0) + 1);
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) res.add(-1);
        Stack<Integer> st = new Stack<>();
        for (int i = arr.length - 1; i >= 0; i--) {
            while (!st.isEmpty() && freq.get(arr[st.peek()]) <= freq.get(arr[i])) st.pop();
            if (!st.isEmpty()) res.set(i, arr[st.peek()]);
            st.push(i);
        }
        return res;
    }
}
