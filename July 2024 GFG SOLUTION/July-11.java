//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int[][] grid = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }

            Solution obj = new Solution();
            int ans = obj.MaxConnection(grid);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


class Solution {
    int n;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public int solve(int i, int j, int[][] grid, int k) {
        grid[i][j] = k;
        int count = 1;
        for (int l = 0; l < 4; ++l) {
            int x = i + dx[l];
            int y = j + dy[l];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                count += solve(x, y, grid, k);
            }
        }
        return count;
    }

    public int MaxConnection(int[][] grid) {
        n = grid.length;
        int k = 2;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = solve(i, j, grid, k);
                    mp.put(k, size);
                    ans = Math.max(ans, size);
                    ++k;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    HashSet<Integer> unique_neighbors = new HashSet<>();
                    int potential_size = 1;
                    for (int l = 0; l < 4; ++l) {
                        int x = i + dx[l];
                        int y = j + dy[l];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            int neighbor_component = grid[x][y];
                            if (unique_neighbors.add(neighbor_component)) {
                                potential_size += mp.get(neighbor_component);
                            }
                        }
                    }
                    ans = Math.max(ans, potential_size);
                }
            }
        }

        return ans;
    }
}
