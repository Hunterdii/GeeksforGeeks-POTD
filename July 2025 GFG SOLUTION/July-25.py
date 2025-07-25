class Solution:
    def maxCircularSum(self, arr):
        def kadane(a):
            max_sum = curr_sum = a[0]
            for i in range(1, len(a)):
                curr_sum = max(a[i], curr_sum + a[i])
                max_sum = max(max_sum, curr_sum)
            return max_sum
        
        max_kadane = kadane(arr)
        total_sum = sum(arr)
        for i in range(len(arr)):
            arr[i] = -arr[i]
        max_circular = total_sum + kadane(arr)
        for i in range(len(arr)):
            arr[i] = -arr[i]
        
        return max_kadane if max_circular == 0 else max(max_kadane, max_circular)
