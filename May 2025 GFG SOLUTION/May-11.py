class Solution:
    def kthLargest(self, arr, k) -> int:
        p = [0]
        for x in arr: p.append(p[-1] + x)
        q = []
        for i in range(len(arr)):
            for j in range(i + 1, len(arr) + 1):
                heapq.heappush(q, p[j] - p[i])
                if len(q) > k: heapq.heappop(q)
        return q[0]


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import heapq

# Position this line where user code will be pasted.

#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        k = int(input())
        ob = Solution()
        res = ob.kthLargest(arr, k)
        print(res)
        print("~")
        t -= 1

# } Driver Code Ends
