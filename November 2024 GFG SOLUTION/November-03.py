class Solution:

    def isLengthEven(self, head):
        fast = head

        while fast is not None and fast.next is not None:
            fast = fast.next.next

        return fast is None

#{ 
 # Driver Code Starts
#main


class Node:
    # Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    # Function to initialize head
    def __init__(self):
        self.head = None

    # Function to insert a new node at the beginning
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    # Utility function to prit the linked LinkedList
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data, end=" ")
            temp = temp.next
        print("")


if __name__ == '__main__':
    t = int(input())
    while (t > 0):
        llist = LinkedList()
        values = input().strip().split()
        for i in reversed(values):
            llist.push(i)
        flag = Solution().isLengthEven(llist.head)
        if flag:
            print("true")
        else:
            print("false")
        print("~")
        t -= 1
# Contributed by: Harshit Sidhwa

# } Driver Code Ends
