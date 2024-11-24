
class Solution:
    def hasFour(self, n: int) -> bool:
        while n > 0:
            if n % 10 == 4:
                return True
            n //= 10
        return False

    def countNumberswith4(self, n: int) -> int:
        ans = 0
        for i in range(n + 1):
            if self.hasFour(i):
                ans += 1
        return ans



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        obj = Solution()
        res = obj.countNumberswith4(n)

        print(res)

# } Driver Code Ends
