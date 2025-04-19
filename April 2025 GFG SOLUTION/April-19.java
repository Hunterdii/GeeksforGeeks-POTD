//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine();
            String[] S = s.split(" ");
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(S[i]);
            }
            Solution ob = new Solution();
            System.out.println(ob.maxXor(arr));

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    static class TrieNode {
        TrieNode[] children = new TrieNode[2];
    }

    public int maxXor(int[] arr) {
        TrieNode root = new TrieNode();
        for (int num : arr) insert(root, num);
        int max = 0;
        for (int num : arr) max = Math.max(max, query(root, num));
        return max;
    }

    private void insert(TrieNode root, int x) {
        TrieNode node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (node.children[bit] == null) node.children[bit] = new TrieNode();
            node = node.children[bit];
        }
    }

    private int query(TrieNode root, int x) {
        TrieNode node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int desiredBit = 1 - bit;
            if (node.children[desiredBit] != null) {
                maxXor |= (1 << i);
                node = node.children[desiredBit];
            } else {
                node = node.children[bit];
            }
        }
        return maxXor;
    }
}

2)
class Solution {
    public int maxXor(int[] arr) {
        int maxXor = 0, mask = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            set.clear();
            int temp = maxXor | (1 << i);
            boolean found = false;
            for (int num : arr) {
                int prefix = num & mask;
                if (set.contains(temp ^ prefix)) {
                    found = true;
                    break;
                }
                set.add(prefix);
            }
            if (found) maxXor = temp;
        }
        return maxXor;
    }
}
