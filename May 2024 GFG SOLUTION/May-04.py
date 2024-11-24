#User function Template for python3

class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

class Solution:
    def buildTree(self, inOrder, postOrder, n):
        postIndex = [n - 1] 
        return self.buildTreeHelper(inOrder, postOrder, 0, n - 1, postIndex)
    
    def buildTreeHelper(self, inOrder, postOrder, inStart, inEnd, postIndex):
        if inStart > inEnd:
            return None

        root = Node(postOrder[postIndex[0]])
        postIndex[0] -= 1 

        inIndex = inOrder.index(root.data) 

        root.right = self.buildTreeHelper(inOrder, postOrder, inIndex + 1, inEnd, postIndex)
        root.left = self.buildTreeHelper(inOrder, postOrder, inStart, inIndex - 1, postIndex)

        return root


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys
from collections import  defaultdict

#Contributed by : PranchalK


_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())



# Helper function that allocates  
# a new node  
class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

# This funtcion is here just to test  
def preOrder(node):
    if node == None:
        return
    print(node.data, end=" ")
    preOrder(node.left)
    preOrder(node.right)
    
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())  # number of nodes in tree
        in_order = list(map(int, input().strip().split()))  # parent child info in list
        post_order = list(map(int, input().strip().split()))  # parent child info in list
        ob = Solution()
        preOrder(ob.buildTree(in_order,post_order,n))
        print()


# } Driver Code Ends
