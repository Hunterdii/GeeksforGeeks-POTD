class Solution:
    def getMedian(self, arr):
        maxH, minH, res = [], [], []

        for n in arr:
            heapq.heappush(maxH, -heapq.heappushpop(minH, n))
            if len(maxH) > len(minH):
                heapq.heappush(minH, -heapq.heappop(maxH))
            res.append(minH[0] if len(minH) > len(maxH) else (-maxH[0] + minH[0]) / 2)
        return res
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.getMedian(nums)
        print(" ".join(f"{x:.1f}" for x in ans))


if __name__ == "__main__":
    main()

# } Driver Code Ends
