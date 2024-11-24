1)
class Solution:
    def pairWithMaxSum(self, arr):
        n = len(arr)

        if n < 2:
            return -1

        max_sum = arr[0] + arr[1]  

        for i in range(1, n - 1):
            max_sum = max(max_sum, arr[i] + arr[i + 1])

        return max_sum

2)
class Solution:
    def pairWithMaxSum(self, arr):
        n = len(arr)
        if n < 2:
            return -1  

        max_sum = arr[0] + arr[1] 
        for i in range(1, n - 1):
            current_sum = arr[i] + arr[i + 1] 
            max_sum = max(max_sum, current_sum) 

        return max_sum

3)
class Solution:
    def pairWithMaxSum(self, arr):
        if len(arr) < 2:
            return -1 
        
        return max(arr[i] + arr[i + 1] for i in range(len(arr) - 1))

#{ 
 # Driver Code Starts
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")

    t = int(data[0])
    lines = data[1:]

    for line in lines:
        s = list(map(int, line.strip().split()))
        solution = Solution()
        res = solution.pairWithMaxSum(s)
        print(res)

# } Driver Code Ends
