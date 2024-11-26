#User function Template for python3

#Complete this function
#Function to find maximum circular subarray sum.
def circularSubarraySum(arr):
    total_sum = 0
    max_sum = float('-inf')
    min_sum = float('inf')
    curr_max = 0
    curr_min = 0
    all_negative = True

    for num in arr:
        total_sum += num

        curr_max = max(num, curr_max + num)
        max_sum = max(max_sum, curr_max)

        curr_min = min(num, curr_min + num)
        min_sum = min(min_sum, curr_min)

        if num > 0:
            all_negative = False

    if all_negative:
        return max_sum

    return max(max_sum, total_sum - min_sum)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
import sys

if __name__ == "__main__":
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]

        print(circularSubarraySum(arr))

        T -= 1

# } Driver Code Ends
