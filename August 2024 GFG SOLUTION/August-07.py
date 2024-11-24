#User function Template for python3

class Solution:
    def kthElement(self, k, arr1, arr2):
        return self.kth(arr1, arr2, 0, len(arr1), 0, len(arr2), k - 1)

    def kth(self, arr1, arr2, s1, e1, s2, e2, k):
        if s1 >= e1:
            return arr2[s2 + k]
        if s2 >= e2:
            return arr1[s1 + k]
        
        mid1 = (e1 - s1) // 2
        mid2 = (e2 - s2) // 2
        
        if mid1 + mid2 < k:
            if arr1[s1 + mid1] > arr2[s2 + mid2]:
                return self.kth(arr1, arr2, s1, e1, s2 + mid2 + 1, e2, k - mid2 - 1)
            else:
                return self.kth(arr1, arr2, s1 + mid1 + 1, e1, s2, e2, k - mid1 - 1)
        else:
            if arr1[s1 + mid1] > arr2[s2 + mid2]:
                return self.kth(arr1, arr2, s1, s1 + mid1, s2, e2, k)
            else:
                return self.kth(arr1, arr2, s1, e1, s2, s2 + mid2, k)
#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while (T > 0):

        k = int(input())
        a = [int(x) for x in input().strip().split()]
        b = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.kthElement(k, a, b))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
