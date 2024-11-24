#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


# } Driver Code Ends
#User function Template for python3
class Solution:
    def findTriplets(self, arr):
        n = len(arr)
        mp = {}
        ans = []

        for i in range(n):
            if arr[i] not in mp:
                mp[arr[i]] = []
            mp[arr[i]].append(i)

        for i in range(n):
            for j in range(i + 1, n):
                num = -(arr[i] + arr[j])
                if num in mp:
                    for index in mp[num]:
                        if index > j:
                            ans.append([i, j, index])

        return ans

#{ 
 # Driver Code Starts.

def main():
    T = int(input())
    while (T > 0):

        A = [int(x) for x in input().strip().split()]

        ob = Solution()
        res = ob.findTriplets(A)
        res = sorted(res)
        if len(res) == 0:
            print('[]')
        for i in range(len(res)):
            for j in range(len(res[i])):
                print(res[i][j], end=" ")
            print("")
        print('~')
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
