#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


# } Driver Code Ends

class Solution:
    def countPairs(self, arr, target):
        freq_map, count = {}, 0
        for num in arr:
            count += freq_map.get(target - num, 0)
            freq_map[num] = freq_map.get(num, 0) + 1
        return count

#{ 
 # Driver Code Starts.

def main():
    T = int(input())
    while (T > 0):

        A = [int(x) for x in input().strip().split()]

        k = int(input())
        ob = Solution()
        print(ob.countPairs(A, k))
        print('~')
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
