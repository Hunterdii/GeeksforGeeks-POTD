//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;
    Node prev;

    Node(int x) {
        data = x;
        next = null;
        prev = null;
    }

    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            Node head = null;
            Node tail = head;

            for (int i = 0; i < n; i++) {
                int temp = sc.nextInt();
                if (head == null) {
                    head = new Node(temp);
                    tail = head;
                } else {
                    Node newNode = new Node(temp);
                    tail.next = newNode;
                    newNode.prev = tail;
                    tail = newNode;
                }
            }
            int x = sc.nextInt();

            Solution obj = new Solution();
            Node res = obj.deleteNode(head, x);

            Node.printList(res);
        }
    }
}

// } Driver Code Ends


class Solution {
    public Node deleteNode(Node head, int x) {
        if (head == null) return null;

        Node current = head;
        for (int i = 1; i < x; ++i) {
            if (current.next == null) return head; 
            current = current.next;
        }
        if (current == head) {
            head = head.next;
            if (head != null) head.prev = null;
            return head;
        }
        Node prev = current.prev;
        Node next = current.next;

        if (prev != null) prev.next = next;
        if (next != null) next.prev = prev;

        return head;
    }
}

