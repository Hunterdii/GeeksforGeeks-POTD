'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''
	
class Solution:
    def segregate(self, head):
        if not head:
            return head
            
        zero = one = two = None
        z_tail = o_tail = t_tail = None
        
        while head:
            next_node = head.next
            head.next = None
            
            if head.data == 0:
                if not zero:
                    zero = z_tail = head
                else:
                    z_tail.next = head
                    z_tail = head
            elif head.data == 1:
                if not one:
                    one = o_tail = head
                else:
                    o_tail.next = head
                    o_tail = head
            else:
                if not two:
                    two = t_tail = head
                else:
                    t_tail.next = head
                    t_tail = head
            head = next_node
        
        if z_tail:
            head = zero
            z_tail.next = one if one else two
            if o_tail:
                o_tail.next = two
        elif o_tail:
            head = one
            o_tail.next = two
        else:
            head = two
            
        return head
