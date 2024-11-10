#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
class Solution:
    def findUnion(self, a, b):
        res = []
        i, j = 0, 0
        n, m = len(a), len(b)

        while i < n and j < m:
            if a[i] < b[j]:
                res.append(a[i])
                i += 1
            elif a[i] > b[j]:
                res.append(b[j])
                j += 1
            else:
                res.append(a[i])
                i += 1
                j += 1
        while i < n:
            res.append(a[i])
            i += 1
        while j < m:
            res.append(b[j])
            j += 1

        return res
#{ 
 # Driver Code Starts.
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        a = list(map(int, input().strip().split()))
        b = list(map(int, input().strip().split()))
        ob = Solution()
        li = ob.findUnion(a, b)
        for val in li:
            print(val, end=' ')
        print()
        print("~")
# } Driver Code Ends
