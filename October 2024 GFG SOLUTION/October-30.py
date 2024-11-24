#User function Template for python3
class Solution:
    def countPairsWithDiffK(self, arr, k):
        num_set = set(arr)
        count = 0

        for x in num_set:
            if (x + k) in num_set:
                count += arr.count(x) * arr.count(x + k)
                
        return count




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        ans = ob.countPairsWithDiffK(arr, k)
        print(ans)
        print("~")
        tc -= 1

# } Driver Code Ends
