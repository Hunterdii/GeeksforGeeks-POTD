#User function Template for python3
class Solution:
    def minTime(self, root, target):
        def maxDepth(node):
            if not node:
                return 0
            return 1 + max(maxDepth(node.left), maxDepth(node.right))
        
        def traverse(node, target):
            if not node:
                return 0
            if node.data == target:
                ret[0] = max(ret[0], maxDepth(node.left))
                ret[0] = max(ret[0], maxDepth(node.right))
                return 1
            
            left = traverse(node.left, target)
            right = traverse(node.right, target)

            if left > 0:
                ret[0] = max(ret[0], left + maxDepth(node.right))
                return left + 1
            
            if right > 0:
                ret[0] = max(ret[0], right + maxDepth(node.left))
                return right + 1

            return 0

        ret = [0]
        traverse(root, target)
        return ret[0]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque

# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root

if __name__=="__main__":
    t=int(input())
    for _ in range(t):
        line=input()
        target=int(input())
        root=buildTree(line)
        print(Solution().minTime(root,target))

# } Driver Code Ends
