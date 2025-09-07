'''
class Node:
    def _init_(self, x):
        self.data = x
        self.next = None
'''

import heapq

class Solution:
    def mergeKLists(self, arr):
        heap = []
        for i, head in enumerate(arr):
            if head: heapq.heappush(heap, (head.data, i, head))
        
        dummy = Node(-1)
        tail = dummy
        while heap:
            _, i, node = heapq.heappop(heap)
            tail.next = node
            tail = node
            if node.next: heapq.heappush(heap, (node.next.data, i, node.next))
        return dummy.next
