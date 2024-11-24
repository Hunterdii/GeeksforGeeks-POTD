#User function Template for python3


#User function Template for python3
class Solution:
    def NBitBinary(self, n):
        out = ""
        li = []
        on=ze=0;
        def util(out,on,ze,n):
           if n==0:
             li.append(out)
             return
           if on==ze:
              util(out+"1",on+1,ze,n-1)
           if on>ze:
              util(out+"1",on+1,ze,n-1)
              util(out+"0",on,ze+1,n-1)
        util(out,on,ze,n)    
        return li

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution()	
		answer = ob.NBitBinary(n)
		for value in answer:
			print(value,end=" ")
		print()


# } Driver Code Ends
