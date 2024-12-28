#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


# } Driver Code Ends
#User function Template for python3
class Solution:
    def findTriplets(self, arr):
        n = len(arr)
        result = set()
        pair_sum_map = {}
      
        for i in range(n):
            for j in range(i + 1, n):
                pair_sum = arr[i] + arr[j]
                if pair_sum not in pair_sum_map:
                    pair_sum_map[pair_sum] = []
                pair_sum_map[pair_sum].append((i, j))
              
        for i in range(n):
            target = -arr[i]
            if target in pair_sum_map:
                for pair in pair_sum_map[target]:
                    if i not in pair: 
                        triplet = tuple(sorted([i, pair[0], pair[1]]))
                        result.add(triplet)
                      
        return sorted([list(triplet) for triplet in result])


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
