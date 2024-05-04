//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

class InorderPostorderToTree {
    public void preOrder(Node root) {
        if (root == null) return;

        System.out.print(root.data + " ");
        preOrder(root.left);

        preOrder(root.right);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        InorderPostorderToTree ip = new InorderPostorderToTree();
        int T = sc.nextInt();
        while (T > 0) {
            int n = sc.nextInt();
            int inorder[] = new int[n];
            int postorder[] = new int[n];
            for (int i = 0; i < n; i++) inorder[i] = sc.nextInt();
            for (int i = 0; i < n; i++) postorder[i] = sc.nextInt();
            GfG g = new GfG();
            Node root = g.buildTree(inorder, postorder, n);
            ip.preOrder(root);
            System.out.println();

            T--;
        }
    }
}

// } Driver Code Ends


/* Tree node structure
class Node
{
    int data;
    Node left;
    Node right;

        Node(int value)
    {
        data = value;
        left = null;
        right = null;
    }
}*/




class GfG {
    Map<Integer, Integer> indexMap = new HashMap<>();

    Node buildTree(int in[], int post[], int n) {
        for (int i = 0; i < n; ++i)
            indexMap.put(in[i], i);

        int postIndex = n - 1; 
        return buildTreeHelper(in, post, 0, n - 1, postIndex);
    }
    
    private Node buildTreeHelper(int in[], int post[], int inStart, int inEnd, int postIndex) {
    if (inStart > inEnd || postIndex < 0) return null;

    Node root = new Node(post[postIndex]); 

    int inIndex = indexMap.get(root.data); 

    int rightSubtreeSize = inEnd - inIndex;

    root.right = buildTreeHelper(in, post, inIndex + 1, inEnd, postIndex - 1);
    root.left = buildTreeHelper(in, post, inStart, inIndex - 1, postIndex - rightSubtreeSize - 1);

    return root;
}
}


