#User function Template for python3

class Solution:
    def PowMod(self, x, n, m):
        if n == 0:
            return 1  # Base case: x^0 is 1

        x %= m
        half = self.PowMod(x, n // 2, m)

        if n % 2 == 0:
            return (half * half) % m
        else:
            return (((half * half) % m) * x) % m


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		x, n , m = input().split()
		x = int(x)
		n = int(n) 
		m = int(m)
		ob = Solution();
		ans = ob.PowMod(x, n, m)
		print(ans)
# } Driver Code Ends
