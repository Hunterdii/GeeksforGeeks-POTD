//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class Main {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = sc.nextLine();
            Scanner ss = new Scanner(input);

            while (ss.hasNextInt()) {
                arr.add(ss.nextInt());
            }

            Node head = new Node(arr.get(0));
            Node tail = head;

            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }

            Solution ob = new Solution();
            Node[] result = ob.alternatingSplitList(head);
            printList(result[0]);
            printList(result[1]);
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    Node[] alternatingSplitList(Node head) {
        if (head == null) return new Node[]{null, null}; 

        Node a_head = null; 
        Node b_head = null; 
        Node a_tail = null; 
        Node b_tail = null; 
        Node current = head; 

        while (current != null) {
            if (a_head == null) {
                a_head = new Node(current.data);
                a_tail = a_head; 
            } else {
                a_tail.next = new Node(current.data);
                a_tail = a_tail.next; 
            }
            current = current.next;

            if (current != null) {
                if (b_head == null) {
                    b_head = new Node(current.data);
                    b_tail = b_head; 
                } else {
                    b_tail.next = new Node(current.data);
                    b_tail = b_tail.next; 
                }
                current = current.next;
            }
        }
        return new Node[]{a_head, b_head}; 
    }
}
