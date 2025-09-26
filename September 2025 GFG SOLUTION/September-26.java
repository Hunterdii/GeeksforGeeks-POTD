class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) {
            for (int i = 0; i < k; i++) {
                dq.addFirst(dq.removeLast());
            }
        } else {
            for (int i = 0; i < k; i++) {
                dq.addLast(dq.removeFirst());
            }
        }
    }
}
