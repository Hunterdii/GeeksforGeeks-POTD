#User function Template for python3
'''
class Node:
    def _init_(self, data):
        self.data = data
        self.next = None

'''

class Solution:
    def alternatingSplitList(self, head):
        if head is None:
            return None, None

        a_head = None
        b_head = None
        a_tail = None
        b_tail = None
        current = head

        while current is not None:
            if a_head is None:
                a_head = Node(current.data)
                a_tail = a_head
            else:
                a_tail.next = Node(current.data)
                a_tail = a_tail.next
            
            current = current.next
            if current is not None:
                if b_head is None:
                    b_head = Node(current.data)
                    b_tail = b_head
                else:
                    b_tail.next = Node(current.data)
                    b_tail = b_tail.next
                
                current = current.next
        
        return a_head, b_head
#{ 
 # Driver Code Starts
class Node:

    def __init__(self, x):
        self.data = x
        self.next = None


def printList(node):
    while node is not None:
        print(node.data, end=" ")
        node = node.next
    print()


if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        head = Node(arr[0])
        tail = head

        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next

        ob = Solution()
        result = ob.alternatingSplitList(head)
        printList(result[0])
        printList(result[1])

# } Driver Code Ends
