#User function Template for python3
import heapq

class Solution:
    def nearlySorted(self, arr, k):
        if k == 0:
            return 
        minHeap = []
        for i in range(min(k + 1, len(arr))):
            heapq.heappush(minHeap, arr[i])

        index = 0
        for i in range(k + 1, len(arr)):
            arr[index] = heapq.heappop(minHeap)
            index += 1
            heapq.heappush(minHeap, arr[i])
        while minHeap:
            arr[index] = heapq.heappop(minHeap)
            index += 1


#{ 
 # Driver Code Starts
# Initial Template for Python 3
# Position this line where user code will be pasted.
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        k = int(input())
        ob = Solution()
        ob.nearlySorted(arr, k)
        print(*arr)
        # print("~")
        t -= 1
# } Driver Code Ends
