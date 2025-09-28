class Solution:
    def longestSubarray(self, arr, x):
        from collections import deque
        minQ, maxQ = deque(), deque()
        n, l, start, maxLen = len(arr), 0, 0, 0
        for r in range(n):
            while minQ and arr[minQ[-1]] >= arr[r]: minQ.pop()
            while maxQ and arr[maxQ[-1]] <= arr[r]: maxQ.pop()
            minQ.append(r)
            maxQ.append(r)
            while arr[maxQ[0]] - arr[minQ[0]] > x:
                if l == minQ[0]: minQ.popleft()
                if l == maxQ[0]: maxQ.popleft()
                l += 1
            if r - l + 1 > maxLen:
                maxLen = r - l + 1
                start = l
        return arr[start:start + maxLen]
