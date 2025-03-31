class Solution:
    def maxPartitions(self, s: str) -> int:
        last = {c: i for i, c in enumerate(s)}
        count = end = 0
        for i, c in enumerate(s):
            end = max(end, last[c])
            if i == end:
                count += 1
        return count


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    tc = int(input())

    for _ in range(tc):
        s = input()
        obj = Solution()
        print(obj.maxPartitions(s))
        print("~")

# } Driver Code Ends
