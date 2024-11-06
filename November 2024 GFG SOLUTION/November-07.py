#User function Template for python3
class Solution:
    def findSplit(self, arr):
        n = len(arr)
        totalSum = sum(arr)

        if totalSum % 3 != 0:
            return [-1, -1]

        target = totalSum // 3
        currentSum = 0
        countFirst = 0

        for i in range(n):
            currentSum += arr[i]

            if currentSum == 2 * target and countFirst > 0:
                return [countFirst - 1, i]

            if currentSum == target:
                countFirst += 1

        return [-1, -1]

#{ 
 # Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        arr = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.findSplit(arr)

        if result == [-1, -1]:
            print("false")
        else:
            print("true")
        print("~")

# } Driver Code Ends
