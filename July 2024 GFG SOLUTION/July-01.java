//{ Driver Code Starts
import java.util.*;
class Tree {
    int data;
    Tree left;
    Tree right;
    Tree(int d) {
        data = d;
        left = null;
        right = null;
    }
} 

class Node {
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
} 

class MakeBT {
    static Node lhead;
    static Queue<Tree> queue = new LinkedList<Tree>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Tree node = null;
            lhead = null;
            Node head = null;
            while (!queue.isEmpty()) {
                queue.poll();
            }
            int n = sc.nextInt();
            if (n != 0) {
                MakeBT llist = new MakeBT();
                int a1 = sc.nextInt();
                head = new Node(a1);
                llist.addToTheLast(head);
                lhead = head;
                for (int i = 1; i < n; i++) {
                    int a = sc.nextInt();
                    llist.addToTheLast(new Node(a));
                }
            }
            GfG g = new GfG();
            Tree root = g.convert(lhead, node);
            try {
                levelOrder(root, n);
            } catch (NullPointerException ex) {
                System.out.println(-1);
            }
            System.out.println();
        }
    }
    public static void levelOrder(Tree root, int n) {
        queue.add(root);
        while (!queue.isEmpty() && n-- > 0) {
            Tree proot = queue.remove();
            try {
                queue.add(proot.left);
                queue.add(proot.right);
                System.out.print(proot.data + " ");
            } catch (NullPointerException ex) {
            }
        }
    }
    public void addToTheLast(Node head) {
        if (lhead == null)
            lhead = head;
        else {
            Node temp = lhead;
            while (temp.next != null) temp = temp.next;
            temp.next = head;
        }
    }
}
// } Driver Code Ends


/*class Tree{
int data;
    Tree left;
    Tree right;
    Tree(int d){
        data=d;
        left=null;
        right=null;
    }
}

class Node {
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
}*/


class GfG {
    public static Tree convert(Node head, Tree node) {
        if (head == null) {
            return null;
        }

        Tree root = new Tree(head.data);
        Queue<Tree> queue = new LinkedList<>();
        queue.add(root);
        head = head.next;

        while (head != null) {
            Tree parent = queue.poll();
            
            Tree leftChild = null, rightChild = null;
            leftChild = new Tree(head.data);
            queue.add(leftChild);
            head = head.next;

            if (head != null) {
                rightChild = new Tree(head.data);
                queue.add(rightChild);
                head = head.next;
            }

            parent.left = leftChild;
            parent.right = rightChild;
        }
        return root;
    }
}
