#User function Template for python3
class Solution:
    def constructLowerArray(self, arr):
        n = len(arr)
        bit = [0] * (n + 1)
        ans = [0] * n

        def update(index, value):
            while index <= n:
                bit[index] += value
                index += index & -index

        def get(index):
            sum = 0
            while index > 0:
                sum += bit[index]
                index -= index & -index
            return sum

        value_index_pairs = [(arr[i], i) for i in range(n)]
        value_index_pairs.sort()

        rank = {value_index_pairs[i][0]: i + 1 for i in range(n)}

        for i in range(n - 1, -1, -1):
            index = rank[arr[i]]
            ans[i] = get(index - 1)
            update(index, 1)

        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.constructLowerArray(arr)
        for x in ans:
            print(x, end=" ")
        print()
        tc -= 1

# } Driver Code Ends
