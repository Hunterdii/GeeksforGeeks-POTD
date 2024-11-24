#User function Template for python3
class Solution:
    def insertAtBottom(self, st, x):
        tmp = []
        
        while st:
            tmp.append(st.pop())
        
        st.append(x)
        
        while tmp:
            st.append(tmp.pop())
        
        return st
        

#{ 
 # Driver Code Starts

if __name__ == "__main__":
    for _ in range(int(input())):
        n,x = map(int,input().split())
        stack = list(map(int,input().split()))
        obj = Solution()
        ans = obj.insertAtBottom(stack,x)
        for e in ans:
            print(e,end=" ")
        print()
        
        
        
# } Driver Code Ends
