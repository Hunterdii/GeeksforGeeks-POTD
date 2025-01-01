#User function Template for python3
from collections import defaultdict

class Solution:
    def anagrams(self, arr):
        umap = defaultdict(list)
        for s in arr:
            sorted_s = ''.join(sorted(s))
            umap[sorted_s].append(s)
        
        return list(umap.values())


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for tcs in range(t):
        words = input().split()

        ob = Solution()
        ans = ob.anagrams(words)

        for grp in sorted(ans):
            for word in grp:
                print(word, end=' ')
            print()

        print("~")

# } Driver Code Ends
