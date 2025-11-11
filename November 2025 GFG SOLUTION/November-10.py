class Solution:
    def maxProfit(self, arr):
        if not arr:
            return 0
        n = len(arr)
        hold = -arr[0]
        sold = 0
        rest = 0
        for price in arr[1:]:
            prev_hold = hold
            prev_sold = sold
            prev_rest = rest
            hold = max(prev_hold, prev_rest - price)
            sold = prev_hold + price
            rest = max(prev_rest, prev_sold)
        return max(sold, rest)
