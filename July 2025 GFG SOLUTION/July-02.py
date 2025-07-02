class Solution:
    def totalElements(self, arr):
        mp = {}
        i = maxLen = 0
        for j in range(len(arr)):
            mp[arr[j]] = mp.get(arr[j], 0) + 1
            while len(mp) > 2:
                mp[arr[i]] -= 1
                if mp[arr[i]] == 0:
                    del mp[arr[i]]
                i += 1
            maxLen = max(maxLen, j - i + 1)
        return maxLen
