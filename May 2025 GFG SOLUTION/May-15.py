class Solution:
    def countSubstring(self, s):
        from collections import Counter
        return sum(v * (v + 1) // 2 for v in Counter(s).values())



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.countSubstring(s)

        print(answer)
        print("~")

# } Driver Code Ends
