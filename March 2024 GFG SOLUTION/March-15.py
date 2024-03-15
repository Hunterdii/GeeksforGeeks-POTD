#User function Template for python3
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        
class Solution:
    def mergeSort(self, head):
        if head is None or head.next is None:
            return head
        
        mid = self.findMiddle(head)
        nextToMid = mid.next
        mid.next = None
        
        left = self.mergeSort(head)
        right = self.mergeSort(nextToMid)
        
        return self.merge(left, right)
    
    def merge(self, left, right):
        if left is None:
            return right
        if right is None:
            return left
        
        result = None
        if left.data <= right.data:
            result = left
            result.next = self.merge(left.next, right)
        else:
            result = right
            result.next = self.merge(left, right.next)
        
        return result
    
    def findMiddle(self, head):
        if head is None:
            return None
        
        slow = head
        fast = head.next
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        return slow
    
    def sort(self, head):
        return self.mergeSort(head)

#Initial Template for Python 3

class Llist:
    def __init__(self):
        self.head=None
    
    def insert(self,data,tail):
        node=Node(data)
        
        if not self.head:
            self.head=node
            return node
        
        tail.next=node
        return node

def printList(head):
    while head:
        print(head.data,end=' ')
        head=head.next

 # Driver Code Starts
#Initial Template for Python 3

class Llist:
    def __init__(self):
        self.head=None
    
    def insert(self,data,tail):
        node=Node(data)
        
        if not self.head:
            self.head=node
            return node
        
        tail.next=node
        return node
        

def printList(head):
    while head:
        print(head.data,end=' ')
        head=head.next
        
if __name__ == '__main__':
    t=int(input())
    
    for tcs in range(t):
        
        n1=int(input())
        arr1=[int(x) for x in input().split()]
        ll1=Llist()
        tail=None
        for nodeData in arr1:
            tail=ll1.insert(nodeData,tail)
            
        
        ob = Solution()
        resHead=ob.sort(ll1.head)
        printList(resHead)
        print()
        
    
    
# } Driver Code Ends
