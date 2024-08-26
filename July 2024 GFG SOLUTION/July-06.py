#User function Template for python3


class Node:

    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
        self.next = None


class Solution:
    def __init__(self):
        self.prev = None

    def populateNext(self, root):
        if not root:
            return

        self.populateNext(root.left)

        if self.prev:
            self.prev.next = root

        self.prev = root

        self.populateNext(root.right)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import defaultdict
from collections import deque
from sys import stdin, stdout


class Node:

    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
        self.next = None


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


def Inorder(root):
    if root.left == None:
        return root
    return Inorder(root.left)


if __name__ == '__main__':
    test_cases = int(input())
    for _ in range(test_cases):
        root = buildTree(input())
        obj = Solution()
        obj.populateNext(root)
        ptr = Inorder(root)
        while ptr:
            print("{}->{}".format(ptr.data,
                                  (ptr.next.data if ptr.next else -1)),
                  end=" ")
            ptr = ptr.next
        print()

# } Driver Code Ends
