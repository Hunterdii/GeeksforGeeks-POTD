class Solution:
    def oddEven(self, s: str) -> str:
        x = 0
        y = 0
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        for i in range(26):
            if count[i] > 0:
                if count[i] % 2 == 0 and (i + 1) % 2 == 0:
                    x += 1
                elif count[i] % 2 == 1 and (i + 1) % 2 == 1:
                    y += 1
        
        sum_value = x + y
        return "ODD" if sum_value % 2 == 1 else "EVEN"

 



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        s = (input())

        obj = Solution()
        res = obj.oddEven(s)

        print(res)

# } Driver Code Ends
