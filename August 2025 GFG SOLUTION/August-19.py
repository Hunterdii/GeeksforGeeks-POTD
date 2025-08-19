class Solution:
    def farMin(self, arr):
        n = len(arr)
        ans = []
        suff = [0] * n
        suff[n-1] = arr[n-1]
        for i in range(n-2, -1, -1):
            suff[i] = min(arr[i], suff[i+1])
        for i in range(n):
            lo, hi, res = i+1, n-1, -1
            while lo <= hi:
                mid = lo + (hi-lo)//2
                if suff[mid] < arr[i]:
                    res = mid
                    lo = mid+1
                else:
                    hi = mid-1
            ans.append(res)
        return ans
