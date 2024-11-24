class Solution:
    def findTriplet(self, arr):
        n = len(arr)
        if n < 3:
            return False

        arr.sort()  # Sort array

        for i in range(n - 1, 1, -1):
            target = arr[i]
            left, right = 0, i - 1

            while left < right:
                sum_ = arr[left] + arr[right]

                if sum_ == target:
                    return True
                elif sum_ < target:
                    left += 1  
                else:
                    right -= 1 

        return False  


#{ 
 # Driver Code Starts
#Initial Template for Python 3
# Position this line where user code will be pasted.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.findTriplet(arr)
        if (res):
            print("true")
        else:
            print("false")
        # print(res)
        print("~")
        t -= 1

# } Driver Code Ends
