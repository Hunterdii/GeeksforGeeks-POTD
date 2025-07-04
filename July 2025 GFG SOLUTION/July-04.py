class Solution:
    def countAtMostK(self, arr, k):
        freq = {}
        n, res, left = len(arr), 0, 0
        for right in range(n):
            freq[arr[right]] = freq.get(arr[right], 0) + 1
            while len(freq) > k:
                freq[arr[left]] -= 1
                if freq[arr[left]] == 0:
                    del freq[arr[left]]
                left += 1
            res += right - left + 1
        return res
