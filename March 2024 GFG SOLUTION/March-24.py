#User function Template for python3
#User function Template for python3
class Solution:
    def insertAtBottom(self, st, x):
        tmp = []
        
        # Push all elements from the original stack to a temporary list
        while st:
            tmp.append(st.pop())
        
        # Push the new element to the bottom of the stack
        st.append(x)
        
        # Push back all elements from the temporary list to the original stack
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
