#User function Template for python3

class Solution:
    def CombinationSum2(self, arr, n, k):
        arr.sort()
        result = []
        temp = []
        self.solve(arr, k, 0, temp, result)
        return result

    def solve(self, arr, target, start, temp, result):
        if target == 0:
            result.append(temp[:])
            return

        for i in range(start, len(arr)):
            if i > start and arr[i] == arr[i - 1]:
                continue
            if arr[i] > target:
                break
            temp.append(arr[i])
            self.solve(arr, target - arr[i], i + 1, temp, result)
            temp.pop()

#{ 
 # Driver Code Starts
#Initial Template for Python 3

for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    ob = Solution()
    result = ob.CombinationSum2(arr, n, k)
    for row in result:
        print(*row)
    if not result:
        print()

# } Driver Code Ends
