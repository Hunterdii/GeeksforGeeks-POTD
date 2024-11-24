//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node right, down;

    Node(int data) {
        this.data = data;
        right = null;
        down = null;
    }
}

public class Linked_list_2D_Matrix {

    // Non-static display method
    void display(Node head) {
        Node Dp = head;
        while (Dp != null) {
            Node Rp = Dp;
            while (Rp != null) {
                System.out.print(Rp.data + " ");
                if (Rp.right != null)
                    System.out.print(Rp.right.data + " ");
                else
                    System.out.print("null ");
                if (Rp.down != null)
                    System.out.print(Rp.down.data + " ");
                else
                    System.out.print("null ");
                Rp = Rp.right;
            }
            Dp = Dp.down;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Linked_list_2D_Matrix ll2d =
            new Linked_list_2D_Matrix(); // Create an instance of the class

        try {
            int t = Integer.parseInt(scanner.nextLine().trim());

            while (t-- > 0) {
                // Read and process the first line of input
                String line = scanner.nextLine().trim();
                if (line.isEmpty()) {
                    continue; // Skip empty lines
                }

                String[] elements = line.split("\\s+");
                int n = elements.length;

                int[] arr = new int[n];
                for (int i = 0; i < n; i++) {
                    arr[i] = Integer.parseInt(elements[i]);
                }

                int[][] mat = new int[n][n];
                mat[0] = arr;

                // Read the remaining rows of the matrix
                for (int i = 1; i < n; i++) {
                    line = scanner.nextLine().trim();
                    elements = line.split("\\s+");
                    for (int j = 0; j < n; j++) {
                        mat[i][j] = Integer.parseInt(elements[j]);
                    }
                }

                Solution obj = new Solution();
                Node head = obj.construct(mat);
                ll2d.display(head); // Call non-static method using instance
                System.out.println();
            }
        } catch (NumberFormatException e) {
            System.err.println(
                "Error reading input. Please ensure the input is in the correct format.");
        } finally {
            scanner.close();
        }
    }
}

// } Driver Code Ends


// User function Template for Java

/*class Node

class Node
{
   int data;
   Node right,down;

   Node(int data){
       this.data = data;
       right = null;
       down = null;
   }
}
*/
/*Function should return the head of the 2D LL.*/
class Solution {
    static Node construct(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        Node[][] nodeMatrix = new Node[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nodeMatrix[i][j] = new Node(mat[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n - 1) {
                    nodeMatrix[i][j].right = nodeMatrix[i][j + 1]; 
                }
                if (i < m - 1) {
                    nodeMatrix[i][j].down = nodeMatrix[i + 1][j]; 
                }
            }
        }

        return nodeMatrix[0][0];
    }
}
