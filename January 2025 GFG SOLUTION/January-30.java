//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine());

            Solution ob = new Solution();
            ArrayList<ArrayList<Integer>> ans = ob.nQueen(n);
            if (ans.size() == 0)
                System.out.println("-1");
            else {
                ans.sort((list1, list2) -> {
                    int size = Math.min(list1.size(), list2.size());
                    for (int i = 0; i < size; i++) {
                        if (!list1.get(i).equals(list2.get(i))) {
                            return list1.get(i) - list2.get(i);
                        }
                    }
                    return list1.size() - list2.size();
                });

                for (int i = 0; i < ans.size(); i++) {
                    System.out.print("[");
                    for (int j = 0; j < ans.get(i).size(); j++)
                        System.out.print(ans.get(i).get(j) + " ");
                    System.out.print("] ");
                }
                System.out.println();
            }

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public ArrayList<ArrayList<Integer>> nQueen(int n) {
        if (n < 4 && n != 1) return new ArrayList<>();
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        int[] row = new int[n];
        solve(0, 0, 0, 0, n, row, res);
        return res;
    }

    private void solve(int c, int cols, int d1, int d2, int n, int[] row, ArrayList<ArrayList<Integer>> res) {
        if (c == n) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int r : row) temp.add(r + 1);
            res.add(temp);
            return;
        }
        for (int r = 0, pos = 1; r < n; ++r, pos <<= 1) 
            if ((cols & pos) == 0 && (d1 & (pos << c)) == 0 && (d2 & (pos << (n - 1 - c))) == 0) {
                row[c] = r;
                solve(c + 1, cols | pos, d1 | (pos << c), d2 | (pos << (n - 1 - c)), n, row, res);
            }
    }
}
