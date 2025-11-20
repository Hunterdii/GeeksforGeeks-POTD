---
title: "🛤️ Shortest Path Using At Most One Curved Edge | GFG Solution 🔍"
keywords🏷️: ["🛤️ shortest path", "🔍 Dijkstra's algorithm", "📍 state tracking", "📈 priority queue", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Shortest Path Using At Most One Curved Edge problem: find minimum path length using Dijkstra with state tracking for curved edge usage. 🚀"
date: 📅 2025-11-21
---

# *21. Shortest Path Using At Most One Curved Edge*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/shortest-path-using-atmost-one-curved-edge--170647/1)

## **🧩 Problem Description**

You are given an undirected, connected graph with `V` vertices numbered from `0` to `V-1` and `E` double-edges. Each double-edge connects vertices `x` and `y` with two options:
- A **straight edge** with weight `w1`
- A **curved edge** with weight `w2`

Your task is to find the **shortest path** from vertex `a` to vertex `b` such that you can use **at most one curved edge** in the entire path. If no such path exists, return `-1`.

## **📘 Examples**

### Example 1

```cpp
Input: V = 4, E = 4, a = 1, b = 3, edges[][] = [[0, 1, 1, 4], [0, 2, 2, 4], [0, 3, 3, 1], [1, 3, 6, 5]]
Output: 2
Explanation: 
Path 1 -> 0 -> 3 using straight edges costs 1 + 3 = 4.
But using the curved edge from 0 -> 3 gives 1 + 1 = 2, which is optimal.
```

### Example 2

```cpp
Input: V = 2, E = 1, a = 0, b = 1, edges[][] = [[0, 1, 4, 1]]
Output: 1
Explanation: 
Take the curved path from 0 to 1 which costs 1.
```

## **🔒 Constraints**

* $1 \le V \le 10^6$
* $0 \le E \le 10^6$
* $0 \le a, b \le V - 1$
* $0 \le \text{edges}[i][0], \text{edges}[i][1] \le V-1$
* $0 \le \text{edges}[i][2], \text{edges}[i][3] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Dijkstra's Algorithm with State Tracking** to handle the constraint of using at most one curved edge:

### **Dijkstra with State Tracking**

1. **Graph Representation:**
   * Build an adjacency list where each edge stores both straight weight `w1` and curved weight `w2`.
   * Each node can be in two states: curved edge **not used** (state 0) or **already used** (state 1).

2. **Distance Array:**
   * Maintain a 2D distance array `d[V][2]` where:
     - `d[u][0]` = minimum distance to node `u` without using any curved edge
     - `d[u][1]` = minimum distance to node `u` after using exactly one curved edge
   * Initialize all distances to infinity, except `d[a][0] = 0`.

3. **Priority Queue:**
   * Use a min-heap priority queue storing `{distance, node, curved_used}`.
   * Process nodes in order of increasing distance.

4. **Relaxation:**
   * For each neighbor `v` of current node `u`:
     - **Straight edge:** Update `d[v][current_state]` using `w1` if it gives a shorter path.
     - **Curved edge:** If curved edge hasn't been used yet (state 0), try updating `d[v][1]` using `w2`.

5. **Result:**
   * Return `min(d[b][0], d[b][1])` as the shortest path to destination `b`.
   * If both are infinity, return `-1`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O((V + E) log V), where V is the number of vertices and E is the number of edges. Each edge is relaxed at most twice (once for each state), and priority queue operations take O(log V) time.
* **Expected Auxiliary Space Complexity:** O(V + E), where O(V) is used for the distance array storing two states per vertex, O(E) for the adjacency list, and O(V) for the priority queue in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
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
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ BFS with State Tracking**

### 💡 Algorithm Steps:

1. Use BFS with queue to explore paths level by level.
2. Track distance for each node in two states: curved edge used or not used.
3. Process nodes in order of distance using deque for 0-1 BFS optimization.
4. Return minimum distance to destination considering both states.

```cpp
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
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O((V + E) log V) - Each edge processed with priority operations
* **Auxiliary Space:** 💾 O(V + E) - Distance array and queue storage

### ✅ **Why This Approach?**

* Efficient exploration using deque optimization
* Natural level-by-level traversal pattern
* Good for graphs with similar edge weights

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1061/1063 test cases due to time constraints).

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Dijkstra Priority Queue**    | 🟢 O((V + E) log V)    | 🟢 O(V + E)             | 🚀 Optimal for sparse graphs      | 🔧 Complex priority queue handling    |
| 🔍 **BFS State Tracking**          | 🟢 O((V + E) log V)    | 🟢 O(V + E)             | 📖 Natural level traversal        | 💾 May TLE on large dense graphs      |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Sparse graphs with many nodes**                  | 🥇 **Dijkstra Priority Queue**       | ★★★★★                     |
| 📖 **Dense graphs with similar weights**             | 🥈 **BFS State Tracking**            | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
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
```

## **🐍 Code (Python)**

```python
class Solution:
    def shortestPath(self, V, a, b, edges):
        from heapq import heappush,heappop
        g=[[] for _ in range(V)]
        for u,v,w1,w2 in edges:
            g[u].append((v,w1,w2))
            g[v].append((u,w1,w2))
        d=[[float('inf')]*2 for _ in range(V)]
        d[a][0]=0
        pq=[(0,a,0)]
        while pq:
            dist,u,c=heappop(pq)
            if dist>d[u][c]:continue
            for v,w1,w2 in g[u]:
                if d[v][c]>dist+w1:
                    d[v][c]=dist+w1
                    heappush(pq,(d[v][c],v,c))
                if not c and d[v][1]>dist+w2:
                    d[v][1]=dist+w2
                    heappush(pq,(d[v][1],v,1))
        res=min(d[b][0],d[b][1])
        return -1 if res==float('inf') else res
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
