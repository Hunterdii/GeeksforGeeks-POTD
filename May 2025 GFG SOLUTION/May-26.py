class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
     

class Solution:
    def sortedInsert(self, head, data):
        n = Node(data)
        if not head:
            n.next = n
            return n
        cur = head
        while True:
            if (cur.data <= data <= cur.next.data or
                cur.data > cur.next.data and (data >= cur.data or data <= cur.next.data) or
                cur.next == head):
                n.next = cur.next
                cur.next = n
                if data < head.data:
                    head = n
                break
            cur = cur.next
        return head
