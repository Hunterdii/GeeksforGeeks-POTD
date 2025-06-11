class Solution {
    public int findLength(int[] color, int[] radius) {
        int j = -1;
        for (int i = 0; i < color.length; ++i) {
            if (j >= 0 && color[i] == color[j] && radius[i] == radius[j])
                j--;
            else {
                ++j;
                color[j] = color[i];
                radius[j] = radius[i];
            }
        }
        return j + 1;
    }
}
