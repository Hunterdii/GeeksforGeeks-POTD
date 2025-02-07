//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class GfG {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            Solution g = new Solution();
            ArrayList<Integer> res = g.inOrder(root);
            for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
            System.out.print("\n");
            t--;

            System.out.println("~");
        }
    }
}

// } Driver Code Ends



/* A Binary Tree node

class Node {
    int data;
    Node left, right;
   Node(int item)    {
        data = item;
        left = right = null;
    }
}
*/
class Solution {
    ArrayList<Integer> inOrder(Node r) {
        ArrayList<Integer> a = new ArrayList<>();
        f(r, a);
        return a;
    }
    void f(Node r, ArrayList<Integer> a) {
        if (r == null) return;
        f(r.left, a);
        a.add(r.data);
        f(r.right, a);
    }
}

2)
class Solution {
    ArrayList<Integer> inOrder(Node root) {
        ArrayList<Integer> result = new ArrayList<>();
        inorderHelper(root, result);
        return result;
    }
    
    void inorderHelper(Node root, ArrayList<Integer> result) {
        if (root == null) return;
        inorderHelper(root.left, result);
        result.add(root.data);
        inorderHelper(root.right, result);
    }
}


3)
class Solution {
    ArrayList<Integer> inOrder(Node r) {
        ArrayList<Integer> a = new ArrayList<>();
        Stack<Node> s = new Stack<>();
        while (r != null || !s.isEmpty()) {
            while (r != null) {
                s.push(r);
                r = r.left;
            }
            r = s.pop();
            a.add(r.data);
            r = r.right;
        }
        return a;
    }
}
