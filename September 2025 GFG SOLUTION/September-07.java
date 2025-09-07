/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

class Solution {
    Node mergeKLists(Node[] arr) {
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.data - b.data);
        for (Node head : arr) if (head != null) pq.offer(head);
        
        Node dummy = new Node(-1), tail = dummy;
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            tail.next = node; tail = node;
            if (node.next != null) pq.offer(node.next);
        }
        return dummy.next;
    }
}
