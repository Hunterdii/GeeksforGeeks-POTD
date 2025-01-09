#User function Template for python3

class Solution:
    def subarraySum(self, arr, target):
        s, curr = 0, 0
        for e in range(len(arr)):
            curr += arr[e]
            while curr > target and s <= e:
                curr -= arr[s]
                s += 1
            if curr == target:
                return [s + 1, e + 1]
        return [-1]
#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        d = int(input().strip())
        ob = Solution()
        result = ob.subarraySum(arr, d)
        print(" ".join(map(str, result)))
        tc -= 1
        print("~")

# } Driver Code Ends
