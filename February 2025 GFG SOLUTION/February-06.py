#User function Template for python3

'''
# Node class
class Node:
    def __init__(self,val):
        self.data = val
        self.right = None
        self.left = None

'''
# Note: Build tree and return root node
class Solution:
    def buildTree(self, inorder, preorder):
        m = {v: i for i, v in enumerate(inorder)}
        self.i = 0
        def f(l, r):
            if l > r: return None
            root = Node(preorder[self.i])
            self.i += 1
            pos = m[root.data]
            root.left = f(l, pos - 1)
            root.right = f(pos + 1, r)
            return root
        return f(0, len(inorder) - 1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3


class Node:

    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None


def printPostorder(n):
    if n is None:
        return
    printPostorder(n.left)
    printPostorder(n.right)
    print(n.data, end=' ')


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        inorder = [int(x) for x in input().split()]
        preorder = [int(x) for x in input().split()]

        root = Solution().buildTree(inorder, preorder)
        printPostorder(root)
        print()

# } Driver Code Ends
