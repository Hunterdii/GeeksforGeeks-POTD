#User function Template for python3

class Solution:
    def longestCommonPrefix(self, arr):
        if not arr:
            return "-1"
        prefix = arr[0]

        for i in range(1, len(arr)):
            while not arr[i].startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return "-1"
        return prefix if prefix else "-1"



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        arr = [x for x in input().strip().split(" ")]

        ob = Solution()
        print(ob.longestCommonPrefix(arr))

# } Driver Code Ends
