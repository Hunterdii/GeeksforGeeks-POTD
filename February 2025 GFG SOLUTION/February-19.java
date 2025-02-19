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
    /* Function to print nodes in a given linked list */
    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    // Driver program to test the above functions
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());

        while (t-- > 0) {
            int n = Integer.parseInt(scanner.nextLine());
            List<Node> lists = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String line = scanner.nextLine();
                String[] values = line.split(" ");
                Node head = null, temp = null;

                for (String value : values) {
                    Node newNode = new Node(Integer.parseInt(value));
                    if (head == null) {
                        head = newNode;
                        temp = head;
                    } else {
                        temp.next = newNode;
                        temp = temp.next;
                    }
                }

                lists.add(head);
            }

            Solution sol = new Solution();
            Node head = sol.mergeKLists(lists);

            printList(head);
            System.out.println("~");
        }
        scanner.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*class Node
{
    int data;
    Node next;

    Node(int key)
    {
        data = key;
        next = null;
    }
}
*/

// arr is an array of Nodes of the heads of linked lists

class Solution {
    Node mergeKLists(List<Node> l) {
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.data));
        for (Node x : l) if (x != null) pq.add(x);
        Node d = new Node(0), t = d;
        while (!pq.isEmpty()) {
            t.next = pq.poll(); t = t.next;
            if (t.next != null) pq.add(t.next);
        }
        return d.next;
    }
}

2)
class Solution {
    Node mergeKLists(List<Node> lists) {
        List<Integer> v = new ArrayList<>();
        for (Node l : lists) while (l != null) { v.add(l.data); l = l.next; }
        Collections.sort(v);
        Node d = new Node(0), t = d;
        for (int x : v) { t.next = new Node(x); t = t.next; }
        return d.next;
    }
}

3)
class Solution {
    Node mergeKLists(List<Node> lists) {
        if (lists.isEmpty()) return null;
        while (lists.size() > 1) {
            List<Node> temp = new ArrayList<>();
            for (int i = 0; i < lists.size(); i += 2) 
                temp.add(merge(lists.get(i), i + 1 < lists.size() ? lists.get(i + 1) : null));
            lists = temp;
        }
        return lists.get(0);
    }

    Node merge(Node a, Node b) {
        if (a == null || b == null) return a != null ? a : b;
        if (a.data > b.data) { Node temp = a; a = b; b = temp; }
        a.next = merge(a.next, b);
        return a;
    }
}
