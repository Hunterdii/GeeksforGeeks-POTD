class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        vector<vector<pair<int,pair<int,int>>>> g(V);
        for(auto &e:edges){
            g[e[0]].push_back({e[1],{e[2],e[3]}});
            g[e[1]].push_back({e[0],{e[2],e[3]}});
        }
        vector<vector<int>> d(V,vector<int>(2,1e9));
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>> pq;
        d[a][0]=0;
        pq.push({0,a,0});
        while(!pq.empty()){
            auto[dist,u,c]=pq.top();pq.pop();
            if(dist>d[u][c])continue;
            for(auto[v,w]:g[u]){
                if(d[v][c]>dist+w.first){
                    d[v][c]=dist+w.first;
                    pq.push({d[v][c],v,c});
                }
                if(!c&&d[v][1]>dist+w.second){
                    d[v][1]=dist+w.second;
                    pq.push({d[v][1],v,1});
                }
            }
        }
        int res=min(d[b][0],d[b][1]);
        return res>=1e9?-1:res;
    }
};

2)
class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        vector<vector<pair<int,pair<int,int>>>> adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],{e[2],e[3]}});
            adj[e[1]].push_back({e[0],{e[2],e[3]}});
        }
        const int INF=1e9;
        vector<array<int,2>> dist(V,{INF,INF});
        deque<array<int,3>> dq;
        dist[a][0]=0;
        dq.push_back({0,a,0});
        while(!dq.empty()){
            auto[d,u,used]=dq.front();dq.pop_front();
            if(d>dist[u][used])continue;
            for(auto[v,wt]:adj[u]){
                if(dist[v][used]>d+wt.first){
                    dist[v][used]=d+wt.first;
                    dq.push_back({dist[v][used],v,used});
                }
                if(!used&&dist[v][1]>d+wt.second){
                    dist[v][1]=d+wt.second;
                    dq.push_back({dist[v][1],v,1});
                }
            }
        }
        int ans=min(dist[b][0],dist[b][1]);
        return ans>=INF?-1:ans;
    }
};
