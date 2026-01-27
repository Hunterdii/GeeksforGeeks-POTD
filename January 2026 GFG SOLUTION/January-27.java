class Solution {
    public boolean isWordExist(char[][] b, String w) {
        for (int i = 0; i < b.length; i++)
            for (int j = 0; j < b[0].length; j++)
                if (search(b, w, i, j, 0)) return true;
        return false;
    }
    
    boolean search(char[][] b, String w, int r, int c, int idx) {
        if (idx == w.length()) return true;
        if (r < 0 || c < 0 || r >= b.length || c >= b[0].length || b[r][c] != w.charAt(idx)) return false;
        char tmp = b[r][c];
        b[r][c] = '*';
        boolean res = search(b, w, r + 1, c, idx + 1) || search(b, w, r - 1, c, idx + 1) ||
                      search(b, w, r, c + 1, idx + 1) || search(b, w, r, c - 1, idx + 1);
        b[r][c] = tmp;
        return res;
    }
}
