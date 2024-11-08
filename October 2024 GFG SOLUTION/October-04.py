#User function Template for python3
'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''
class Solution:

    def reverse(self, head):
        if head is None or head.next == head:
            return head

        prev = head
        current = head.next
        nextNode = None

        while current != head:
            nextNode = current.next
            current.next = prev
            prev = current
            current = nextNode

        head.next = prev  
        return prev  

    def deleteNode(self, head, key):
        if head is None:
            return head

        current = head
        prev = None

        while True:
            if current.data == key:
                if current == head and current.next == head:
                    return None  

                if current == head:

                    tail = head
                    while tail.next != head:
                        tail = tail.next
                    head = current.next  
                    tail.next = head  
                else:
                    prev.next = current.next  
                return head

            prev = current
            current = current.next

            if current == head:
                break  

        return head  

#{ 
 # Driver Code Starts
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def printList(head):
    if head is None:
        print("empty")
        return

    temp = head
    while True:
        print(temp.data, end=" ")
        temp = temp.next
        if temp == head:
            break
    print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        key = int(input())

        head = Node(arr[0])
        tail = head
        for i in range(1, len(arr)):
            tail.next = Node(arr[i])
            tail = tail.next
        tail.next = head  # Make the list circular

        ob = Solution()
        head = ob.deleteNode(head, key)
        head = ob.reverse(head)
        printList(head)

# } Driver Code Ends
