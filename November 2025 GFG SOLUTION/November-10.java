class Solution {
    public int maxProfit(int arr[]) {
        int n = arr.length;
        if (n <= 1) return 0;
        int buy = -arr[0], sell = 0, cooldown = 0;
        for (int i = 1; i < n; i++) {
            int prevBuy = buy, prevSell = sell;
            buy = Math.max(buy, cooldown - arr[i]);
            sell = Math.max(sell, prevBuy + arr[i]);
            cooldown = Math.max(cooldown, prevSell);
        }
        return Math.max(sell, cooldown);
    }
}
