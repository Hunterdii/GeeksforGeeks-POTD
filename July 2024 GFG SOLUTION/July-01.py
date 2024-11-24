# Back-end complete function Template for Python 3

class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

class TreeNode:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def convert(head):
    if head is None:
        return None

    root = TreeNode(head.data)
    queue = [root]
    head = head.next

    while head:
        parent = queue.pop(0)

        if head:
            left_child = TreeNode(head.data)
            parent.left = left_child
            queue.append(left_child)
            head = head.next

        if head:
            right_child = TreeNode(head.data)
            parent.right = right_child
            queue.append(right_child)
            head = head.next

    return root



#{ 
 # Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nikhil Kumar Singh

# Linked List node


class ListNode:

    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.next = None


# Tree Node structure
class Tree:

    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Class to convert the linked list to Binary Tree
class Conversion:
    # Constructor for storing head of linked list
    # and root for the Binary Tree
    def __init__(self, data=None):
        self.head = None
        self.root = None

    def push(self, new_data):

        # Creating a new linked list node and storing data
        new_node = ListNode(new_data)

        # Make next of new node as head
        new_node.next = self.head

        # Move the head to point to new node
        self.head = new_node

    def levelorderTraversal(self, root):
        mylist = []  # reverse list of nodes
        if root is None:
            return
        que = []
        que.append(root)
        while True:
            n = len(que)
            if n == 0:
                break
            while (n > 0):
                node = que.pop(0)
                mylist.append(node.data)
                if node.left is not None:
                    que.append(node.left)
                if node.right is not None:
                    que.append(node.right)
                n -= 1
        mylist = mylist[::-1]
        print(*mylist)
        return


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        a = list(map(int, input().strip().split()))
        mylist = Conversion()  # Create Linked List to be used
        for i in range(n):
            mylist.push(a[i])  # push elements in linked list
        # convert the linked list to binary tree
        root = convert(mylist.head)
        mylist.levelorderTraversal(root)

# } Driver Code Ends
