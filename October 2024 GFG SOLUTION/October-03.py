class Solution:
    def findMajority(self, nums):
        n = len(nums)
        if n == 0:
            return [-1]  

        num1, num2 = -1, -1
        c1, c2 = 0, 0
        
        for x in nums:
            if x == num1:
                c1 += 1
            elif x == num2:
                c2 += 1
            elif c1 == 0:
                num1 = x
                c1 = 1
            elif c2 == 0:
                num2 = x
                c2 = 1
            else:
                c1 -= 1
                c2 -= 1
        
        c1, c2 = 0, 0
        for x in nums:
            if x == num1:
                c1 += 1
            elif x == num2:
                c2 += 1
        
        res = []
        if c1 > n // 3:
            res.append(num1)
        if c2 > n // 3:
            res.append(num2)
        
        if not res:
            res.append(-1)  
        
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.findMajority(nums)
        print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()

# } Driver Code Ends
