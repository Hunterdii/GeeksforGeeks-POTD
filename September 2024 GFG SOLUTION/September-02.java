//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int[][] grid = new int[n][n];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < n; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            int ans = obj.minimumCostPath(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

class Solution {
    static class Cell implements Comparable<Cell> {
        int x, y, distance;

        Cell(int x, int y, int distance) {
            this.x = x;
            this.y = y;
            this.distance = distance;
        }

        public int compareTo(Cell other) {
            return Integer.compare(this.distance, other.distance);
        }
    }

    public int minimumCostPath(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[n][m];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        PriorityQueue<Cell> pq = new PriorityQueue<>();
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        
        dp[0][0] = grid[0][0];
        pq.offer(new Cell(0, 0, dp[0][0]));

        while (!pq.isEmpty()) {
            Cell cur = pq.poll();
            int x = cur.x;
            int y = cur.y;
            int dist = cur.distance;

            if (dist > dp[x][y]) continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newDist = dp[x][y] + grid[nx][ny];
                    if (newDist < dp[nx][ny]) {
                        dp[nx][ny] = newDist;
                        pq.offer(new Cell(nx, ny, newDist));
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }
}
