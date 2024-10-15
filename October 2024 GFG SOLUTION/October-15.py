#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

class Solution:
    def subArraySum(self, arr, target):
        prefixSumMap = {0: 1}  
        curr_sum = 0
        count = 0
        
        for num in arr:
            curr_sum += num
            if (curr_sum - target) in prefixSumMap:
                count += prefixSumMap[curr_sum - target]
            prefixSumMap[curr_sum] = prefixSumMap.get(curr_sum, 0) + 1
        
        return count


#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        tar= int(input())
        ob = Solution()
        res = ob.subArraySum(arr,tar)
        print(res)
        # print("~")
        t -= 1


# } Driver Code Ends
