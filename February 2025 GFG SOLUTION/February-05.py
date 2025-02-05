#User function Template for python3

'''
class Node:
    def _init_(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
# your task is to complete this function

# class Solution:
#     def mirror(self, root):
#         if not root: return
#         self.mirror(root.left)
#         self.mirror(root.right)
#         root.left, root.right = root.right, root.left

class Solution:
    def mirror(self, root):
        if not root:
            return
        self.mirror(root.left)
        self.mirror(root.right)
        root.left, root.right = root.right, root.left
#{ 
 # Driver Code Starts
#Initial Template for Python 3

#Contributed by Sudarshan Sharma
from collections import deque


# Tree Node
class Node:

    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


from collections import deque


class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def levelOrder(root):
    if root is None:
        return "N\n"

    result = []
    qq = deque()
    qq.append(root)

    while qq:
        curr = qq.popleft()

        if curr is None:
            result.append("N")
            continue

        result.append(str(curr.data))
        qq.append(curr.left)
        qq.append(curr.right)

    # Remove trailing non-numeric elements
    while result and not result[-1].isnumeric():
        result.pop()

    return " ".join(result)


def inorderTraversal(root):
    # Code here
    inorderTraversalUtil(root)
    print()


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


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        Solution().mirror(root)
        print(levelOrder(root))
        print("~")

# } Driver Code Ends
