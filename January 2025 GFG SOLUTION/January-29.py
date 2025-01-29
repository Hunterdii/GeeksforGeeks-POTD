#{ 
 # Driver Code Starts
#Initial Template for Python 3


# } Driver Code Ends
#User function Template for python3
class Solution:
    def power(self, b: float, e: int) -> float:
        result = 1.0
        exp = abs(e)
        while exp > 0:
            if exp % 2 == 1:
                result *= b
            b *= b
            exp //= 2
        return result if e >= 0 else 1.0 / result
#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        b = float(input())
        e = int(input())
        ob = Solution()
        result = ob.power(b, e)
        print(f"{result:.5f}")
        print("~")
# } Driver Code Ends
