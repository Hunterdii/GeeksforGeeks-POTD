class Solution:
    def isPossible(self, arr, k, w, maxHeight):
        n = len(arr)
        water = [0] * n
        for i in range(n):
            if i > 0:
                water[i] = water[i - 1]
            currHeight = arr[i] + water[i]
            if i >= w:
                currHeight -= water[i - w]
            if currHeight < maxHeight:
                add = maxHeight - currHeight
                water[i] += add
                k -= add
                if k < 0:
                    return False
        return True
    
    def maxMinHeight(self, arr, k, w):
        n = len(arr)
        low = min(arr)
        high = low + k
        ans = low
        while low <= high:
            mid = low + (high - low) // 2
            if self.isPossible(arr, k, w, mid):
                ans = max(ans, mid)
                low = mid + 1
            else:
                high = mid - 1
        return ans
