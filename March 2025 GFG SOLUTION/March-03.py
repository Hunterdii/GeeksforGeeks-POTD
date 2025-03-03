from collections import deque

class Solution:
    def longestSubarray(self, arr, x):
        minQ, maxQ, start, resStart, resEnd = deque(), deque(), 0, 0, 0
        for end in range(len(arr)):
            while minQ and arr[minQ[-1]] > arr[end]: minQ.pop()
            while maxQ and arr[maxQ[-1]] < arr[end]: maxQ.pop()
            minQ.append(end), maxQ.append(end)
            while arr[maxQ[0]] - arr[minQ[0]] > x:
                if minQ[0] == start: minQ.popleft()
                if maxQ[0] == start: maxQ.popleft()
                start += 1
            if end - start > resEnd - resStart: resStart, resEnd = start, end
        return arr[resStart:resEnd + 1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        ans = ob.longestSubarray(arr, k)

        print(" ".join(map(str, ans)))
        tc -= 1
        print("~")

# } Driver Code Ends
