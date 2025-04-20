class Solution:
    def findDuplicate(self, a):
        s = f = a[0]
        while True:
            s = a[s]
            f = a[a[f]]
            if s == f: break
        f = a[0]
        while s != f:
            s = a[s]
            f = a[f]
        return s


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        print(ob.findDuplicate(arr))
        print("~")

# } Driver Code Ends
