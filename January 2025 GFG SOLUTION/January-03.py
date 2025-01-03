class Solution:
    def subarrayXor(self, arr, k):
        res, prefXOR = 0, 0
        count = {0: 1}
        for val in arr:
            prefXOR ^= val
            res += count.get(prefXOR ^ k, 0)
            count[prefXOR] = count.get(prefXOR, 0) + 1
        return res

#{ 
 # Driver Code Starts
if __name__ == "__main__":
    tc = int(input())

    for _ in range(tc):
        arr = list(map(int, input().split()))
        k = int(input())

        obj = Solution()
        print(obj.subarrayXor(arr, k))
        print("~")

# } Driver Code Ends
