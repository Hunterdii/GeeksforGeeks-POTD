#User function Template for python3
class Solution:
    def findMin(self, arr):
        lo, hi = 0, len(arr) - 1
        while lo < hi:
            if arr[lo] < arr[hi]:
                return arr[lo]
            mid = lo + ((hi - lo) // 2)
            if arr[mid] > arr[hi]:
                lo = mid + 1
            else:
                hi = mid
        return arr[lo]


#{ 
 # Driver Code Starts
def main():
    T = int(input())

    while T > 0:
        a = list(map(
            int,
            input().strip().split()))  # Convert input to list of integers
        print(Solution().findMin(a))  # Call findMin with the array 'a'
        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
