#Your task is to complete this function
#Your function should return the new head pointer

class node:
    def __init__(self,x):
        self.data = x
        self.next = None

class Solution:
    def deleteK(self, head, k):
        if not head or k <= 0:
            return head
        
        if k == 1:
            # Deleting entire list
            while head:
                temp = head
                head = head.next
                temp = None
            return None

        dummy = node(0)
        dummy.next = head
        prev = dummy
        curr = head
        index = 1

        while curr:
            if index == k:
                prev.next = curr.next
                curr = None
                curr = prev.next
                index = 1
            else:
                index += 1
                prev = curr
                curr = curr.next

        return dummy.next
#{ 
 # Driver Code Starts
class node:

    def __init__(self, x):
        self.data = x
        self.next = None


def createLinkedList(arr):
    head = node(arr[0])
    curr = head
    for i in range(1, len(arr)):
        new_node = node(arr[i])
        curr.next = new_node
        curr = curr.next

    return head


def printlist(ptr):
    while ptr != None:
        print(ptr.data, end=" ")
        ptr = ptr.next
    print()


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        k = int(input())

        obj = Solution()
        head = createLinkedList(arr)
        new_head = obj.deleteK(head, k)
        printlist(new_head)

# } Driver Code Ends
