#User function Template for Python 

class Solution:
    def printKClosest(self, arr, n, k, x):
       
        def findCrossOver(arr, low, high, x):
            if arr[high] <= x:
                return high
            if arr[low] > x:
                return low
            mid = (low + high) // 2
            if arr[mid] <= x and arr[mid + 1] > x:
                return mid
            elif arr[mid] < x:
                return findCrossOver(arr, mid + 1, high, x)
            return findCrossOver(arr, low, mid - 1, x)
        
        result = []
        closest = []
        
        l = findCrossOver(arr, 0, n - 1, x) 
        r = l + 1 
        count = 0
        
        if arr[l] == x: 
            l -= 1
       
        
        while l >= 0 and r < n and count < k:
            if (x - arr[l] < arr[r] - x):
                closest.append(arr[l])
                l -= 1
            else:
                closest.append(arr[r])
                r += 1
            count += 1
        
        
        while (count < k and l >= 0):
            closest.append(arr[l])
            l -= 1
            count += 1
        
       
        while (count < k and r < n):
            closest.append(arr[r])
            r += 1
            count += 1
        
        return closest



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        k, x = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.printKClosest(arr, n, k, x)
        for xx in ans:
            print(xx, end=" ")
        print()
        tc -= 1

# } Driver Code Ends
