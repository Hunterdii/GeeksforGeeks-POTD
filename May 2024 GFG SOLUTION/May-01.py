#User function Template for python3

"""
# Node Class

class Node:
    def __init__(self, val):
        self.data = val
        self.next = None

"""

class Solution:
    def arrangeCV(self, head):
        dummy1 = Node('-') 
        ptr1 = dummy1
        dummy2 = Node('-') 
        ptr2 = dummy2
        
        curr = head
        while curr:
            c = curr.data
            if c in ['a', 'e', 'i', 'o', 'u']:
                ptr1.next = curr
                ptr1 = ptr1.next
            else:
                ptr2.next = curr
                ptr2 = ptr2.next
            curr = curr.next
        
        ptr1.next = dummy2.next
        ptr2.next = None 
        
        newHead = dummy1.next
        return newHead


#{ 
 # Driver Code Starts
# Node Class
class Node:

    def __init__(self, val):
        self.data = val
        self.next = None


# Linked List Class
class Linked_List:

    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next


def printList(head):
    tmp = head
    while tmp:
        print(tmp.data, end=' ')
        tmp = tmp.next
    print()


if __name__ == '__main__':
    for i in range(int(input())):
        n = int(input())
        arr = [str(x) for x in input().split()]

        lis = Linked_List()
        for i in arr:
            lis.insert(i)

        newHead = Solution().arrangeCV(lis.head)
        printList(newHead)

# } Driver Code Ends
