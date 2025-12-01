class Solution {
    class Node {
        Node[] ch = new Node[2];
        int cnt = 0;
    }
    void add(Node r, int v) {
        for (int i = 31; i >= 0; i--) {
            int b = (v >> i) & 1;
            if (r.ch[b] == null) r.ch[b] = new Node();
            r.ch[b].cnt++;
            r = r.ch[b];
        }
    }
    int query(Node r, int v, int k) {
        int res = 0;
        for (int i = 31; i >= 0 && r != null; i--) {
            int bv = (v >> i) & 1, bk = (k >> i) & 1;
            if (bk == 1) {
                if (r.ch[bv] != null) res += r.ch[bv].cnt;
                r = r.ch[1 - bv];
            } else r = r.ch[bv];
        }
        return res;
    }
    public int cntPairs(int[] a, int k) {
        Node r = new Node();
        int ans = 0;
        for (int x : a) {
            ans += query(r, x, k);
            add(r, x);
        }
        return ans;
    }
}
