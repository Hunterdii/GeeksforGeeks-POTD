class Solution:
    def alternateSort(self, arr):
        arr.sort()  
        n = len(arr)
        ans = []
        
        left, right = 0, n - 1
        highTurn = True
        
        for _ in range(n):
            if highTurn:
                ans.append(arr[right])
                right -= 1
            else:
                ans.append(arr[left])
                left += 1
            highTurn = not highTurn
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3
#Position this line where user code will be pasted.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.alternateSort(arr)
        print(*ans)
        print("~")
        t -= 1

# } Driver Code Ends