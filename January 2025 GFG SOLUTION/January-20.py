#User function Template for python3
'''
# Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None

'''
class Solution:
    def sortedMerge(self, head1, head2):
        dummy = Node(0)
        tail = dummy
        while head1 and head2:
            if head1.data <= head2.data:
                tail.next = head1
                head1 = head1.next
            else:
                tail.next = head2
                head2 = head2.next
            tail = tail.next
        tail.next = head1 or head2
        return dummy.next

#{ 
 # Driver Code Starts
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def print_list(head):
    temp = head
    while temp:
        print(temp.data, end=' ')
        temp = temp.next
    print()
    print("~")


def insert_sorted(head, data):
    new_node = Node(data)
    if not head or head.data >= data:
        new_node.next = head
        return new_node

    current = head
    while current.next and current.next.data < data:
        current = current.next

    new_node.next = current.next
    current.next = new_node

    return head


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        input1 = list(map(int, input().split()))
        input2 = list(map(int, input().split()))

        head1 = None
        for item in input1:
            head1 = insert_sorted(head1, item)

        head2 = None
        for item in input2:
            head2 = insert_sorted(head2, item)

        obj = Solution()
        merged_head = obj.sortedMerge(head1, head2)
        print_list(merged_head)

# } Driver Code Ends
