#User function Template for python3
class Solution:
    def kthMissing(self, arr, k):
        lo, hi = 0, len(arr)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if arr[mid] - (mid + 1) < k:
                lo = mid + 1
            else:
                hi = mid
        return lo + k




#{ 
 # Driver Code Starts
#Initial Template for Python 3

#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.kthMissing(A, D)
        print(ans)
        print("~")

# } Driver Code Ends
