class Solution:
    def primeList(self, h):
        m = 0; p = h
        while p: m = max(m, p.val); p = p.next
        s = [1]*(2*m+1); s[0] = s[1] = 0
        for i in range(2, int((2*m)**0.5)+1):
            if s[i]: s[i*i:2*m+1:i] = [0]*len(range(i*i, 2*m+1, i))
        p = h
        while p:
            x, d = p.val, 0
            while 1:
                if x-d > 1 and s[x-d]: p.val = x-d; break
                if x+d <= 2*m and s[x+d]: p.val = x+d; break
                d += 1
            p = p.next
        return h

#{ 
 # Driver Code Starts
class Node:

    def __init__(self, x):
        self.val = x
        self.next = None


def printList(node):
    while (node != None):
        print(node.val, end=" ")
        node = node.next
    print()


def inputList():

    val = [int(i) for i in input().strip().split()
           ]  #all data of linked list in a line
    head = Node(val[0])
    tail = head
    for i in range(1, len(val)):
        tail.next = Node(val[i])
        tail = tail.next
    return head


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        head = inputList()

        obj = Solution()
        res = obj.primeList(head)

        printList(res)

        print("~")

# } Driver Code Ends
