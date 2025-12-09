class Solution {
    public static int countSubs(String s) {
        class Node { Node[] c = new Node[26]; }
        Node root = new Node();
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            Node cur = root;
            for (int j = i; j < n; j++) {
                int idx = s.charAt(j) - 'a';
                if (cur.c[idx] == null) {
                    cur.c[idx] = new Node();
                    cnt++;
                }
                cur = cur.c[idx];
            }
        }
        return cnt;
    }
}
