#User function Template for python3
class Solution:
  def countPairs(self, mat1, mat2, n, x):
    count = 0
    r1 = 0
    c1 = 0
    r2 = n - 1
    c2 = n - 1

    while (r1 < n) and (r2 >= 0):
      val = mat1[r1][c1] + mat2[r2][c2]

      if val == x:
        count += 1
        c1 += 1
        c2 -= 1
      elif val < x:
        c1 += 1
      else:
        c2 -= 1

      # Handle boundary conditions within the loop
      if c1 == n:
        c1 = 0
        r1 += 1
      if c2 == -1:
        c2 = n - 1
        r2 -= 1

    return count

 # Driver Code Starts
#Initial Template for Python 3

if _name_ == '_main_':
	T=int(input())
	for i in range(T):
		n , x = input().split()
		n,x = int(n), int(x)
		mat1 = []
		for _ in range(n):
			a = [int(x) for x in input().split()]
			mat1.append(a)

		mat2 = []
		for _ in range(n):
			a = [int(x) for x in input().split()]
			mat2.append(a)

		ob = Solution()
		ans = ob.countPairs(mat1, mat2, n, x)
		print(ans)

# } Driver Code Ends
