//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class Node  
{ 
    int data; 
    Node left, right; 
   
    public Node(int d)  
    { 
        data = d; 
        left = right = null; 
    } 
}

class GFG
{
    static Node buildTree(String str)
    {
        // Corner Case
        if(str.length() == 0 || str.equals('N'))
            return null;
        String[] s = str.split(" ");
        
        Node root = new Node(Integer.parseInt(s[0]));
        Queue <Node> q = new LinkedList<Node>();
        q.add(root);
        
        // Starting from the second element
        int i = 1;
        while(!q.isEmpty() && i < s.length)
        {
              // Get and remove the front of the queue
              Node currNode = q.remove();
        
              // Get the curr node's value from the string
              String currVal = s[i];
        
              // If the left child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the left child for the curr node
                  currNode.left = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.left);
              }
        
              // For the right child
              i++;
              if(i >= s.length)
                  break;
              currVal = s[i];
        
              // If the right child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the right child for the curr node
                  currNode.right = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.right);
              }
              
              i++;
        }
    
        return root;
    }
    
    public static void main(String args[]) throws IOException {
    
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t>0)
        {
            String s = br.readLine();
            Node root = buildTree(s);
            
            Solution T = new Solution();
            System.out.println(T.largestBst(root));
            
            t--;
        }
    }
}


// } Driver Code Ends

// User function Template for Java

class Info {
    boolean isBST;
    int size;
    int minVal;
    int maxVal;

    Info(boolean isBST, int size, int minVal, int maxVal) {
        this.isBST = isBST;
        this.size = size;
        this.minVal = minVal;
        this.maxVal = maxVal;
    }
}

class Solution {
    private Info largestBSTHelper(Node root) {
        if (root == null) {
            return new Info(true, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);
        }

        Info leftInfo = largestBSTHelper(root.left);
        Info rightInfo = largestBSTHelper(root.right);

        if (leftInfo.isBST && rightInfo.isBST && root.data > leftInfo.maxVal && root.data < rightInfo.minVal) {
            return new Info(true, 1 + leftInfo.size + rightInfo.size, Math.min(root.data, leftInfo.minVal), Math.max(root.data, rightInfo.maxVal));
        } else {
            return new Info(false, Math.max(leftInfo.size, rightInfo.size), Integer.MAX_VALUE, Integer.MIN_VALUE);
        }
    }

    public int largestBst(Node root) {
        return largestBSTHelper(root).size;
    }
}
