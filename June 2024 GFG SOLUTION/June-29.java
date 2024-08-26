//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {

            Node head1 = null, head2 = null, tail1 = null, tail2 = null;

            // Input first LL
            int n1 = sc.nextInt();
            int d1 = sc.nextInt();
            head1 = new Node(d1);
            tail1 = head1;

            while (n1-- > 1) {
                Node n = new Node(sc.nextInt());
                tail1.next = n;
                tail1 = tail1.next;
            }

            // Input second LL
            int n2 = sc.nextInt();
            int d2 = sc.nextInt();
            head2 = new Node(d2);
            tail2 = head2;

            while (n2-- > 1) {
                Node n = new Node(sc.nextInt());
                tail2.next = n;
                tail2 = tail2.next;
            }

            Solution obj = new Solution();
            if (obj.areIdentical(head1, head2))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }

    public static void po(Object o) { System.out.println(o); }

    public static void show(Node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        System.out.println();
    }
}

// } Driver Code Ends


/*
class Node {
    int data;
    Node next;

    public Node(int data){
        this.data = data;
        this.next = null;
    }
}*/

class Solution {
    public boolean areIdentical(Node head1, Node head2) {
        while (head1 != null && head2 != null) {
            if (head1.data != head2.data)
                return false;
            head1 = head1.next;
            head2 = head2.next;
        }
        return (head1 == null && head2 == null);
    }
}
