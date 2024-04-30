//{ Driver Code Starts
// driver

import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GfG{
    
    static void printList(Node n){
        while(n!=null){
            System.out.print(n.data+" ");
            n = n.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            
            int n = sc.nextInt();
            int val = sc.nextInt();
            
            Node num1 = new Node(val);
            Node tail = num1;
            for(int i=0; i<n-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            int m = sc.nextInt();
            val = sc.nextInt();
            
            Node num2 = new Node(val);
            tail = num2;
            for(int i=0; i<m-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            Solution g = new Solution();
            Node res = g.addTwoLists(num1, num2);
            printList(res);
        }
    }
}

// } Driver Code Ends


/* node for linked list

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

*/

class Solution {
    static Node reverse(Node head) {
        Node prev = null;
        Node current = head;
        Node next = null;

        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    static Node addTwoLists(Node num1, Node num2) {
        num1 = reverse(num1);
        num2 = reverse(num2);

        Node sum = null;
        int carry = 0;

        while (num1 != null || num2 != null || carry > 0) {
            int newVal = carry;

            if (num1 != null) {
                newVal += num1.data;
                num1 = num1.next;
            }
            if (num2 != null) {
                newVal += num2.data;
                num2 = num2.next;
            }

            carry = newVal / 10;

            newVal = newVal % 10;

            Node newNode = new Node(newVal);

            newNode.next = sum;

            sum = newNode;
        }

        while (sum != null && sum.data == 0) {
            Node temp = sum.next;
            sum.next = null;
            sum = temp;
        }

        if (sum == null)
            return new Node(0);
        return sum;
    }
}
