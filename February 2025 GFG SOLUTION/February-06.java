//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
        left = right = null;
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            Node root = null;

            // Read inorder array
            String[] inorderStr = (br.readLine()).trim().split(" ");
            int inorder[] = new int[inorderStr.length];
            for (int i = 0; i < inorderStr.length; i++) {
                inorder[i] = Integer.parseInt(inorderStr[i]);
            }

            // Read preorder array
            String[] preorderStr = (br.readLine()).trim().split(" ");
            int preorder[] = new int[preorderStr.length];
            for (int i = 0; i < preorderStr.length; i++) {
                preorder[i] = Integer.parseInt(preorderStr[i]);
            }

            Solution ob = new Solution();
            root = ob.buildTree(inorder, preorder);
            postOrder(root);
            System.out.println();
        }
    }

    // Function to print postorder traversal of the tree
    public static void postOrder(Node root) {
        if (root == null) return;

        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data + " ");
    }
}

// } Driver Code Ends


/*
class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
        left = right = null;
    }
}
*/

class Solution {
    public static Node buildTree(int[] in, int[] pre) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < in.length; i++) m.put(in[i], i);
        int[] idx = new int[1];
        return f(0, in.length - 1, pre, m, idx);
    }
    static Node f(int l, int r, int[] pre, HashMap<Integer, Integer> m, int[] idx) {
        if(l > r) return null;
        Node root = new Node(pre[idx[0]++]);
        int pos = m.get(root.data);
        root.left = f(l, pos - 1, pre, m, idx);
        root.right = f(pos + 1, r, pre, m, idx);
        return root;
    }
}


2)
class Solution {
    static int i;
    static HashMap<Integer, Integer> m;
    public static Node buildTree(int[] inorder, int[] preorder) {
        i = 0;
        m = new HashMap<>();
        for (int j = 0; j < inorder.length; j++) m.put(inorder[j], j);
        return f(inorder, preorder, 0, inorder.length - 1);
    }
    static Node f(int[] in, int[] pre, int l, int r) {
        if (l > r) return null;
        Node root = new Node(pre[i++]);
        root.left = f(in, pre, l, m.get(root.data) - 1);
        root.right = f(in, pre, m.get(root.data) + 1, r);
        return root;
    }
}
