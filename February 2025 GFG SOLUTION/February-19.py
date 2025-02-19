#User function Template for python3
'''
class Node:
    def _init_(self,x):
        self.data = x
        self.next = None
'''
class Solution:
    def mergeKLists(self, l):
        pq, d = [], Node(0)
        for x in l: 
            if x: heapq.heappush(pq, (x.data, x))
        t = d
        while pq:
            _, t.next = heapq.heappop(pq)
            t = t.next
            if t.next: heapq.heappush(pq, (t.next.data, t.next))
        return d.next

2)
class Solution:
    def mergeKLists(self, lists):
        if not lists: return None
        while len(lists) > 1:
            temp = []
            for i in range(0, len(lists), 2):
                temp.append(self.merge(lists[i], lists[i+1] if i+1 < len(lists) else None))
            lists = temp
        return lists[0]

    def merge(self, a, b):
        if not a or not b: return a or b
        if a.data > b.data: a, b = b, a
        a.next = self.merge(a.next, b)
        return a

3)
class Solution:
    def mergeKLists(self, lists):
        v = []
        for l in lists:
            while l: v.append(l.data); l = l.next
        v.sort()
        d = Node(0); t = d
        for x in v: t.next = Node(x); t = t.next
        return d.next

#{ 
 # Driver Code Starts
import heapq


class Node:

    def __init__(self, x):
        self.data = x
        self.next = None

    # To compare nodes in the heap
    def __lt__(self, other):
        return self.data < other.data


def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        lists = []
        for _ in range(n):
            values = list(map(int, input().split()))
            head = None
            temp = None
            for value in values:
                newNode = Node(value)
                if head is None:
                    head = newNode
                    temp = head
                else:
                    temp.next = newNode
                    temp = temp.next
            lists.append(head)

        sol = Solution()
        head = sol.mergeKLists(lists)
        printList(head)
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
