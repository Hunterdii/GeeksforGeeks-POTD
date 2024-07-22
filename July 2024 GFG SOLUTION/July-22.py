#User function Template for python3
class Info:
    def __init__(self, is_bst, size, min_val, max_val):
        self.is_bst = is_bst
        self.size = size
        self.min_val = min_val
        self.max_val = max_val

class Solution:
    def largestBSTHelper(self, root):
        if root is None:
            return Info(True, 0, float('inf'), float('-inf'))
        
        left_info = self.largestBSTHelper(root.left)
        right_info = self.largestBSTHelper(root.right)
        
        if left_info.is_bst and right_info.is_bst and root.data > left_info.max_val and root.data < right_info.min_val:
            return Info(True, 1 + left_info.size + right_info.size, min(root.data, left_info.min_val), max(root.data, right_info.max_val))
        else:
            return Info(False, max(left_info.size, right_info.size), float('inf'), float('-inf'))
    
    def largestBst(self, root):
        return self.largestBSTHelper(root).size


#{ 
 # Driver Code Starts
from collections import deque


# Tree Node
class Node:

    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    # Corner Case
    if len(s) == 0 or s[0] == "N":
        return None

    # Creating list of strings from input string after splitting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size += 1

    # Starting from the second element
    i = 1
    while size > 0 and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.popleft()
        size -= 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))
            # Push it to the queue
            q.append(currNode.left)
            size += 1

        # Move to the next element
        i += 1
        if i >= len(ip):
            break

        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))
            # Push it to the queue
            q.append(currNode.right)
            size += 1

        # Move to the next element
        i += 1

    return root


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        root = buildTree(s)
        ob = Solution()
        result = ob.largestBst(root)
        print(result)

# } Driver Code Ends
