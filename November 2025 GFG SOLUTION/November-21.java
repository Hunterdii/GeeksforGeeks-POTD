class Solution {
    public int shortestPath(int V, int a, int b, int[][] edges) {
        List<List<int[]>> g=new ArrayList<>();
        for(int i=0;i<V;i++)g.add(new ArrayList<>());
        for(int[] e:edges){
            g.get(e[0]).add(new int[]{e[1],e[2],e[3]});
            g.get(e[1]).add(new int[]{e[0],e[2],e[3]});
        }
        int[][] d=new int[V][2];
        for(int[] r:d)Arrays.fill(r,1000000000);
        PriorityQueue<int[]> pq=new PriorityQueue<>((x,y)->x[0]-y[0]);
        d[a][0]=0;
        pq.offer(new int[]{0,a,0});
        while(!pq.isEmpty()){
            int[] cur=pq.poll();
            int dist=cur[0],u=cur[1],c=cur[2];
            if(dist>d[u][c])continue;
            for(int[] nxt:g.get(u)){
                int v=nxt[0],w1=nxt[1],w2=nxt[2];
                if(d[v][c]>dist+w1){
                    d[v][c]=dist+w1;
                    pq.offer(new int[]{d[v][c],v,c});
                }
                if(c==0&&d[v][1]>dist+w2){
                    d[v][1]=dist+w2;
                    pq.offer(new int[]{d[v][1],v,1});
                }
            }
        }
        int res=Math.min(d[b][0],d[b][1]);
        return res>=1000000000?-1:res;
    }
}
