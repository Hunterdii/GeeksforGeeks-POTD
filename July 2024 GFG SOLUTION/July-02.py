#User function Template for python3

'''
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
'''
def compute(head):
    ans = ""
    t = head
    while t:
        ans += t.data
        t = t.next
    i, j = 0, len(ans) - 1
    while i < j:
        if ans[i] != ans[j]:
            return False
        i += 1
        j -= 1
    return True




#{ 
 # Driver Code Starts
#Initial Template for Python 3


#contributed by RavinderSinghPB
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class Llist:

    def __init__(self):
        self.head = None

    def insert(self, data, tail):
        node = Node(data)

        if not self.head:
            self.head = node
            return node

        tail.next = node
        return node


if __name__ == '__main__':
    t = int(input())
    for tcs in range(t):

        n1 = int(input())
        arr1 = input().split()
        ll1 = Llist()
        tail = None
        for nodeData in arr1:
            tail = ll1.insert(nodeData, tail)

        if compute(ll1.head):
            print('true')
        else:
            print('false')

# } Driver Code Ends
