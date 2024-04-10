#User function Template for python3

class Solution:    
    # function to convert a given Gray equivalent n to Binary equivalent.
    def grayToBinary(self,n):
        binary = 0
        while n != 0:
            binary ^= n
            n >>= 1
        return binary

 # Driver Code Starts
#Initial Template for Python 3

import math

def main():    
    T=int(input())
    while(T>0): 
        n=int(input())
        ob=Solution()
        print(ob.grayToBinary(n))
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends
