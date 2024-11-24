# class Node:
#     def _init_(self):
#         self.data = None
#         self.left = None
#         self.right = None
        
class Solution:
    def inorder(self, root, prev, minDiff):
        if not root:
            return
        self.inorder(root.left, prev, minDiff)
        if prev[0] != float('inf'):
            minDiff[0] = min(minDiff[0], root.data - prev[0])
        prev[0] = root.data
        self.inorder(root.right, prev, minDiff)

    def absolute_diff(self, root):
        minDiff = [float('inf')]
        prev = [float('inf')]
        self.inorder(root, prev, minDiff)
        return minDiff[0]
        


#{ 
 # Driver Code Starts

from collections import deque

class Node:
    def _init_(self, data):
        self.data = data
        self.left = None
        self.right = None

# Function to Build Tree
def buildTree(str):
    # Corner Case
    if len(str) == 0 or str[0] == 'N':
        return None

    # Creating list of strings from input string after splitting by space
    ip = str.split()

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    queue = deque()
    queue.append(root)

    # Starting from the second element
    i = 1
    while queue and i < len(ip):
        # Get and remove the front of the queue
        currNode = queue.popleft()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            queue.append(currNode.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            queue.append(currNode.right)

        i += 1

    return root

for _ in range(int(input())):
    s = input()
    root = buildTree(s)
    if root is None:
        continue
    if root.left is None and root.right is None:
        continue
    
    ob = Solution()
    print(ob.absolute_diff(root))

# } Driver Code Ends
