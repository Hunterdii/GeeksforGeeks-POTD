class Solution:
    def findSwapValues(self, a, n, b, m):
        sumA = sum(a)
        sumB = sum(b)
        if (sumA - sumB) % 2 != 0:
            return -1
        target = (sumA - sumB) // 2
        setB = set(b)
        for num in a:
            if (num - target) in setB:
                return 1
        return -1

#{ 
 # Driver Code Starts
if __name__ == '__main__': 
    
    
    t=int(input())
    for _ in range(0,t):
        l=list(map(int,input().split()))
        n=l[0]
        m=l[1]
        a = list(map(int,input().split()))
        b = list(map(int, input().split()))
        ob = Solution()
        print(ob.findSwapValues(a,n,b,m))
# } Driver Code Ends
