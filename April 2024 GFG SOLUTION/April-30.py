#User function Template for python3

#User function Template for python3

''' Node for linked list:

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''
class Solution:
    #Function to add two numbers represented by linked list.
    def addTwoLists(self, num1, num2):
        # Reverse both lists to simplify addition.
        num1 = self.reverse(num1)
        num2 = self.reverse(num2)

        sum = None
        carry = 0

        while num1 or num2 or carry:
            newVal = carry

            if num1:
                newVal += num1.data
                num1 = num1.next
            if num2:
                newVal += num2.data
                num2 = num2.next

            carry = newVal // 10
            newVal %= 10

            newNode = Node(newVal)
            newNode.next = sum
            sum = newNode

        return self.removeLeadingZeros(sum)

    #Function to reverse the linked list.
    def reverse(self, head):
        prev = None
        current = head

        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next

        return prev

    #Function to remove leading zeros from the result.
    def removeLeadingZeros(self, head):
        current = head
        prev = None

        while current and current.data == 0:
            prev = current
            current = current.next
            prev.next = None

        return current if current else Node(0)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next

# prints the elements of linked list starting with head
def printList(n):
    while n:
        print(n.data,end=' ')
        n = n.next
    print()

if __name__ == '__main__':
    for _ in range(int(input())):
        
        n = int(input())
        arr1 = ( int(x) for x in input().split() )
        num1 = LinkedList()
        for i in arr1:
            num1.insert(i)
        
        m = int(input())
        arr2 = ( int(x) for x in input().split() )
        num2 = LinkedList()
        for i in arr2:
            num2.insert(i)
        
        res = Solution().addTwoLists(num1.head, num2.head)
        printList(res)
# } Driver Code Ends
