//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class Node {
    Node next;
    int val;

    public Node(int data) {
        val = data;
        next = null;
    }
}

class Main {
    public static void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t;
        t = Integer.parseInt(in.readLine());
        while (t-- > 0) {

            Node head, tail;
            String s[] = in.readLine().trim().split(" ");
            int num = Integer.parseInt(s[0]);
            head = new Node(num);
            tail = head;
            for (int i = 1; i < s.length; i++) {
                num = Integer.parseInt(s[i]);
                tail.next = new Node(num);
                tail = tail.next;
            }
            Solution ob = new Solution();
            Node temp = ob.primeList(head);
            while (temp != null) {
                out.print(temp.val + " ");
                temp = temp.next;
            }
            out.println();
            out.println("~");
        }
        out.close();
    }
}
// } Driver Code Ends


// User function Template for Java
/*
class Node{
    Node next;
    int val;
    public Node(int data){
        val=data;
        next=null;
    }
}
*/

class Solution {
    Node primeList(Node h) {
        int m = 0;
        for (Node p = h; p != null; p = p.next) m = Math.max(m, p.val);
        boolean[] s = new boolean[2*m+1];
        Arrays.fill(s, true);
        s[0] = s[1] = false;
        for (int i = 2; i*i <= 2*m; i++)
            if (s[i])
                for (int j = i*i; j <= 2*m; j += i) s[j] = false;
        for (Node p = h; p != null; p = p.next) {
            int x = p.val, d = 0;
            while (true) {
                if (x-d > 1 && s[x-d]) { p.val = x-d; break; }
                if (x+d <= 2*m && s[x+d]) { p.val = x+d; break; }
                d++;
            }
        }
        return h;
    }
}


// 2) Solution @itsjomon

class Solution {
    Node primeList(Node head) {
        int max = 0;
        for (Node cur = head; cur != null; cur = cur.next)
            max = Math.max(max, cur.val);
        boolean[] p = new boolean[max + 100];
        Arrays.fill(p, true);
        p[0] = p[1] = false;
        for (int i = 2; i * i < p.length; i++)
            if (p[i])
                for (int j = i * i; j < p.length; j += i)
                    p[j] = false;
        for (Node cur = head; cur != null; cur = cur.next) {
            if (!p[cur.val]) {
                int l = cur.val - 1, r = cur.val + 1;
                while (true) {
                    if (l >= 2 && p[l]) {
                        cur.val = l;
                        break;
                    }
                    if (r < p.length && p[r]) {
                        cur.val = r;
                        break;
                    }
                    l--; r++;
                }
            }
        }
        return head;
    }
}

