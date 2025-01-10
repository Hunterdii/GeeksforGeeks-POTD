#User function Template for python3
class Solution:
    def countTriangles(self, arr):
        arr.sort()
        n, count = len(arr), 0
        for i in range(n - 1, 1, -1):
            l, r = 0, i - 1
            while l < r:
                if arr[l] + arr[r] > arr[i]:
                    count += r - l
                    r -= 1
                else:
                    l += 1
        return count

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.countTriangles(arr))

        print("~")

# } Driver Code Ends
