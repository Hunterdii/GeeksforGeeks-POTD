class Solution:
    def minimumPlatform(self, arr, dep):
        arr.sort(); dep.sort()
        i = j = cnt = ans = 0
        n = len(arr)
        while i < n and j < n:
            if arr[i] <= dep[j]:
                cnt += 1; ans = max(ans, cnt); i += 1
            else:
                cnt -= 1; j += 1
        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        arrival = list(map(int, input().strip().split()))
        departure = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.minimumPlatform(arrival, departure))
        print("~")

# } Driver Code Ends
