
from typing import List

class Solution:
    def getPrimes(self, n: int) -> List[int]:
        if n <= 2:
            return [-1, -1] 
        isPrime = [True] * (n + 1)
        isPrime[0] = isPrime[1] = False
        for i in range(2, int(n**0.5) + 1):
            if isPrime[i]:
                for j in range(i * i, n + 1, i):
                    isPrime[j] = False
        
        result = [-1, -1]
        for i in range(2, n // 2 + 1):
            if isPrime[i] and isPrime[n - i]:
                result[0] = i
                result[1] = n - i
                break
        
        return result       
#{ 
 # Driver Code Starts
class IntArray:

    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  #array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        obj = Solution()
        res = obj.getPrimes(n)

        IntArray().Print(res)

# } Driver Code Ends
