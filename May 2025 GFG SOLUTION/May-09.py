class Solution:
    def findMaximumNum(self, s, k):
        ans = [s]
        def r(a, k, i):
            if k == 0 or i == len(a): return
            m = max(a[i:])
            if m != a[i]:
                for j in range(len(a)-1, i-1, -1):
                    if a[j] == m:
                        a[i], a[j] = a[j], a[i]
                        cur = ''.join(a)
                        if cur > ans[0]: ans[0] = cur
                        r(a, k-1, i+1)
                        a[i], a[j] = a[j], a[i]
            else:
                r(a, k, i+1)
        r(list(s), k, 0)
        return ans[0]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        k = int(input())
        s = input()
        ob = Solution()
        print(ob.findMaximumNum(s, k))

        print("~")

# } Driver Code Ends
