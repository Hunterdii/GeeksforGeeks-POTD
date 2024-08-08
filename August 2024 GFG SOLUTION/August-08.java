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
class Solution {
  public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    final int[] dx = {1, 0, -1, 0};
    final int[] dy = {0, 1, 0, -1};
    List<int[]> ans = new ArrayList<>(Arrays.asList(new int[] {rStart, cStart}));

    for (int i = 0; ans.size() < rows * cols; ++i)
      for (int step = 0; step < i / 2 + 1; ++step) {
        rStart += dy[i % 4];
        cStart += dx[i % 4];
        if (0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols)
          ans.add(new int[] {rStart, cStart});
      }

    return ans.stream().toArray(int[][] ::new);
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
            System.out.println(g.isSumTree(root));
            // if (g.isSumTree(root) == true)
            //     System.out.println(1);
            // else
            //     System.out.println(0);
            t--;
        }
    }
}

// } Driver Code Ends


/* A Binary Tree node
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/
class Solution {
    boolean isLeaf(Node node) {
        return (node != null && node.left == null && node.right == null);
    }

    boolean checkSumTree(Node node, int[] sum) {
        if (node == null) {
            sum[0] = 0;
            return true;
        }
        if (isLeaf(node)) {
            sum[0] = node.data;
            return true;
        }

        int[] leftSum = {0}, rightSum = {0};

        if (checkSumTree(node.left, leftSum) && checkSumTree(node.right, rightSum)) {
            sum[0] = node.data + leftSum[0] + rightSum[0];
            return node.data == leftSum[0] + rightSum[0];
        }

        return false;
    }

    boolean isSumTree(Node root) {
        int[] sum = {0};
        return checkSumTree(root, sum);
    }
}

