//{ Driver Code Starts
import java.lang.*;
import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int key) {
        data = key;
        left = right = null;
    }
}

class CreateTree {
    static ArrayList<Integer> result = new ArrayList<Integer>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int arr[] = new int[n];

            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            Solution ob = new Solution();
            Node root = ob.createTree(arr);

            printLevelOrder(root);
            System.out.println();
        }
    }

    public static void printList(Node root) {
        while (root != null) {
            System.out.print(root.data + " ");
        }
    }

    public static void printLevelOrder(Node root) {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++) {
            result.clear();
            printGivenLevel(root, i);
            Collections.sort(result);
            for (int j = 0; j < result.size(); j++)
                System.out.print(result.get(j) + " ");
        }
    }

    public static int height(Node root) {
        if (root == null)
            return 0;

        else {

            int lheight = height(root.left);
            int rheight = height(root.right);

            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }

    public static void printGivenLevel(Node node, int level) {
        if (node == null) return;
        if (level == 1)
            result.add(node.data);
        else if (level > 1) {
            printGivenLevel(node.left, level - 1);
            printGivenLevel(node.right, level - 1);
        }
    }
}

// } Driver Code Ends


/*node class of the binary tree
class Node
{
    int data;
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
}*/
class Solution {
    public Node createTree(int[] parent) {
        int n = parent.length;
        Node[] created = new Node[n];
        Node root = null;

        for (int i = 0; i < n; i++) {
            if (created[i] == null) {
                createNode(parent, i, created);
            }
        }

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = created[i];
                break;
            }
        }

        return root;
    }

    private void createNode(int[] parent, int i, Node[] created) {
        if (created[i] != null) return;

        created[i] = new Node(i);

        if (parent[i] == -1) return;

        if (created[parent[i]] == null) {
            createNode(parent, parent[i], created);
        }

        Node p = created[parent[i]];
        if (p.left == null) {
            p.left = created[i];
        } else {
            p.right = created[i];
        }
    }
}


