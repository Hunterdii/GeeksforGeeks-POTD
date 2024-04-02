//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;
 class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
class GFG {

static Node buildTree(String str){
        
        if(str.length()==0 || str.charAt(0)=='N'){
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
        while(queue.size()>0 && i < ip.length) {
            
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
                
            // Get the current node's value from the string
            String currVal = ip[i];
                
            // If the left child is not null
            if(!currVal.equals("N")) {
                    
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }
                
            // For the right child
            i++;
            if(i >= ip.length)
                break;
                
            currVal = ip[i];
                
            // If the right child is not null
            if(!currVal.equals("N")) {
                    
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
    BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
    int T=Integer.parseInt(bu.readLine());
    while (T-- > 0) {
      
      String s=bu.readLine();
      Node root = buildTree(s);
       if (root == null)
        continue;
      if (root.left == null && root.right == null)
        continue;
      Solution obj = new Solution();
      int ans = obj.absolute_diff(root);
      System.out.println(ans);
    }
  }
}

// } Driver Code Ends


//User function Template for Java

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/
class Solution {
    void inorder(Node root, int[] prev, int[] minDiff) {
        if (root == null) return;
        inorder(root.left, prev, minDiff);
        if (prev[0] != Integer.MAX_VALUE) {
            minDiff[0] = Math.min(minDiff[0], root.data - prev[0]);
        }
        prev[0] = root.data;
        inorder(root.right, prev, minDiff);
    }

    int absolute_diff(Node root) {
        int[] minDiff = {Integer.MAX_VALUE};
        int[] prev = {Integer.MAX_VALUE};
        inorder(root, prev, minDiff);
        return minDiff[0];
    }
}
