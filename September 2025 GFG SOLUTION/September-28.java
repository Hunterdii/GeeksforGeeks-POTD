class Solution {
    public ArrayList<Integer> longestSubarray(int[] arr, int x) {
        ArrayDeque<Integer> minQ = new ArrayDeque<>(), maxQ = new ArrayDeque<>();
        int n = arr.length, l = 0, start = 0, maxLen = 0;
        for (int r = 0; r < n; r++) {
            while (!minQ.isEmpty() && arr[minQ.peekLast()] >= arr[r]) minQ.removeLast();
            while (!maxQ.isEmpty() && arr[maxQ.peekLast()] <= arr[r]) maxQ.removeLast();
            minQ.addLast(r);
            maxQ.addLast(r);
            while (arr[maxQ.peekFirst()] - arr[minQ.peekFirst()] > x) {
                if (l == minQ.peekFirst()) minQ.removeFirst();
                if (l == maxQ.peekFirst()) maxQ.removeFirst();
                l++;
            }
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = start; i < start + maxLen; i++) result.add(arr[i]);
        return result;
    }
}
