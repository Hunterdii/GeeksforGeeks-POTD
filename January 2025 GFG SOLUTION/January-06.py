#User function Template for python3
class Solution:
    def sumClosest(self, arr, target):
        arr.sort()
        l, r, minDiff, res = 0, len(arr) - 1, float('inf'), []
        while l < r:
            s = arr[l] + arr[r]
            if abs(target - s) < minDiff:
                minDiff, res = abs(target - s), [arr[l], arr[r]]
            l += s < target
            r -= s >= target
        return res



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input().strip())
    while t > 0:
        arr = list(map(int, input().strip().split()))
        target = int(input().strip())
        ob = Solution()
        ans = ob.sumClosest(arr, target)
        if not ans:
            print("[]")
        else:
            print(*ans)
        print("~")
        t -= 1

# } Driver Code Ends
