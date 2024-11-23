#User function Template for python3
class Solution:
    def getMinDiff(self, k: int, arr: list) -> int:
        n = len(arr)
        modified = []
        count = [0] * n

        for i in range(n):
            modified.append((arr[i] - k, i))
            modified.append((arr[i] + k, i))

        modified.sort()

        left = 0
        elements_in_range = 0
        ans = float('inf')

        for right in range(len(modified)):
            if count[modified[right][1]] == 0:
                elements_in_range += 1
            count[modified[right][1]] += 1

            while elements_in_range == n:
                ans = min(ans, modified[right][0] - modified[left][0])

                if count[modified[left][1]] == 1:
                    elements_in_range -= 1
                count[modified[left][1]] -= 1
                left += 1

        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.getMinDiff(k, arr)
        print(res)
        print("~")

# } Driver Code Ends
