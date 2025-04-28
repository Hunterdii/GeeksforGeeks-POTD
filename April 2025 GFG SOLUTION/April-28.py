#User function Template for python3

'''
# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

# class Solution:
#     def f(self,r):
#         if not r: return (0,0)
#         l,rgt=self.f(r.left),self.f(r.right)
#         return (r.data+l[1]+rgt[1],max(l)+max(rgt))
#     def getMaxSum(self,root):
#         return max(self.f(root))


class Solution:
    def solve(self,r):
        if not r: return (0,0)
        l,r1=self.solve(r.left),self.solve(r.right)
        return (r.data+l[1]+r1[1],max(l)+max(r1))
    def getMaxSum(self,root):
        return max(self.solve(root))

#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
import sys
from collections import defaultdict
from collections import deque

sys.setrecursionlimit(10**6)


class Node:

    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


# Function to Build Tree
def buildTree(s):
    #Corner Case
    if (len(s) == 0 or s[0] == "N"):
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while (size > 0 and i < len(ip)):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if (currVal != "N"):

            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if (i >= len(ip)):
            break
        currVal = ip[i]

        # If the right child is not null
        if (currVal != "N"):

            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1
    return root


if __name__ == '__main__':
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        ob = Solution()
        print(ob.getMaxSum(root))

        print("~")

# } Driver Code Ends
