//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

class LinkedList {
    // Function to print nodes in a given circular linked list
    static void printList(Node head) {
        if (head == null) {
            System.out.println("empty");
            return;
        }
        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            int key = Integer.parseInt(br.readLine());
            Node head = new Node(arr.get(0));
            Node tail = head;
            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }
            tail.next = head; // Make the list circular
            Solution ob = new Solution();
            Node current = ob.deleteNode(head, key);
            Node rev = ob.reverse(current);
            printList(rev);
        }
    }
}

// } Driver Code Ends


/*class Node
{
    int data;
    Node next;
    Node(int d)
    {
        data=d;next=null;
    }
}*/

class Solution {

    Node reverse(Node head) {
        if (head == null || head.next == head) {
            return head; 
        }

        Node prev = head;
        Node current = head.next;
        Node nextNode;

        while (current != head) {
            nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }

        head.next = prev; 
        return prev; 
    }

    Node deleteNode(Node head, int key) {
        if (head == null) {
            return head; 
        }

        Node current = head, prev = null;

        do {
            if (current.data == key) {
                if (current == head && current.next == head) {
                    return null; 
                }

                if (current == head) {
                    Node tail = head;
                    while (tail.next != head) { 
                        tail = tail.next;
                    }
                    head = current.next; 
                    tail.next = head; 
                } else {
                    prev.next = current.next; 
                }
                return head; 
            }
            prev = current; 
            current = current.next; 
        } while (current != head);

        return head; 
    }
}
