class Solution {
    public ArrayList<Integer> minMaxCandy(int[] prices, int k) {
        Arrays.sort(prices);
        int n = prices.length, min = 0, max = 0;
        for (int i = 0, rem = n; i < rem; i++, rem -= k) min += prices[i];
        for (int j = n - 1, idx = -1; j > idx; j--, idx += k) max += prices[j];
        return new ArrayList<>(Arrays.asList(min, max));
    }
}
