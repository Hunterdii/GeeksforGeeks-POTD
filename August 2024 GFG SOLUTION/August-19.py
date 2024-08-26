#User function Template for python3

class Solution:
    def kthSmallest(self, arr, k):
        min_element = min(arr)
        max_element = max(arr)
        range_size = max_element - min_element + 1
        
        freq = [0] * range_size
        
        for num in arr:
            freq[num - min_element] += 1
        
        count = 0
        for i in range(range_size):
            count += freq[i]
            if count >= k:
                return i + min_element
        
        return -1
#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__':
    import random
    t = int(input())
    for tcs in range(t):
        # n = int(input())
        arr = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.kthSmallest(arr, k))

# } Driver Code Ends
