#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
class Solution:
    def findMaxProduct(self, arr):
        mod = int(1e9 + 7)
        neg_count = 0
        max_neg = float('-inf')
        pos_product = 1
        neg_product = 1
        has_non_zero = False

        for num in arr:
            if num < 0:
                neg_count += 1
                max_neg = max(max_neg, num)

        skip_max_neg = (neg_count % 2 == 1)

        for num in arr:
            if num < 0:
                if skip_max_neg and num == max_neg:
                    skip_max_neg = False
                    continue
                neg_product = (neg_product * abs(num)) % mod
            elif num > 0:
                pos_product = (pos_product * num) % mod
                has_non_zero = True

        if not has_non_zero and neg_count <= 1:
            return 0
        return (neg_product * pos_product) % mod

#{ 
 # Driver Code Starts.
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    t = int(data[index])
    index += 1
    results = []
    
    for _ in range(t):
        n = int(data[index])
        index += 1
        arr = list(map(int, data[index:index + n]))
        index += n
        solution = Solution()
        ans = solution.findMaxProduct(arr)
        results.append(ans)
    
    for result in results:
        print(result)
# } Driver Code Ends
