# User function Template for python3
class Solution:
    def longestSubarray(self, arr, k):
        mp, sum, res = {}, 0, 0
        for i, num in enumerate(arr):
            sum += num
            if sum == k:
                res = i + 1
            if sum - k in mp:
                res = max(res, i - mp[sum - k])
            mp.setdefault(sum, i)
        return res
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        print(ob.longestSubarray(arr, k))
        tc -= 1
        print("~")
# } Driver Code Ends
