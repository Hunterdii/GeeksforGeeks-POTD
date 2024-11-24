//{ Driver Code Starts
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Node {
    char data;
    Node next;
    
    public Node(char data){
        this.data = data;
        next = null;
    }
}

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    Node head = null, tail = null;
		    
		    char head_c = sc.next().charAt(0);
		    head = new Node(head_c);
		    tail = head;
		    
		    while(n-- > 1){
		        tail.next = new Node(sc.next().charAt(0));
		        tail = tail.next;
		    }
		    
		    Solution obj = new Solution();
		    //show(head);
		    show(obj.arrangeCV(head));
		    
		}
	}
	
	public static void po(Object o){
	    System.out.println(o);
	}
	
	public static void show(Node head){
        while(head != null){
            System.out.print(head.data+" ");
            head = head.next;
        }
        System.out.println();
    }
}

// } Driver Code Ends


/*
Structure of node class is:
class Node {
    char data;
    Node next;
    
    public Node(char data){
        this.data = data;
        next = null;
    }
}
*/
class Solution {
    
    public Node arrangeCV(Node head){
        Node dummy1 = new Node('-');
        Node ptr1 = dummy1;
        Node dummy2 = new Node('-'); 
        Node ptr2 = dummy2;
        
        for (Node curr = head; curr != null; curr = curr.next) {
            char c = curr.data;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ptr1.next = curr;
                ptr1 = ptr1.next;
            } else {
                ptr2.next = curr;
                ptr2 = ptr2.next;
            }
        }
        
        ptr1.next = dummy2.next;
        ptr2.next = null; 
        
        Node newHead = dummy1.next;
        return newHead;
    }
}
