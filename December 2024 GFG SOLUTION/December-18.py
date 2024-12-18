class Solution:
    def findPages(self, arr, k):
        n = len(arr)
        if k > n:
            return -1  

        low, high = max(arr), sum(arr)  

        while low < high:
            mid = (low + high) // 2
            students, current_sum = 1, 0

            for pages in arr:
                if current_sum + pages > mid:
                    students += 1
                    current_sum = pages
                else:
                    current_sum += pages

            if students > k:
                low = mid + 1
            else:
                high = mid

        return low
#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.findPages(A, D)
        print(ans)
        print("~")

# } Driver Code Ends
