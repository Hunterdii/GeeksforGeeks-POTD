//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution {
public:
    vector<int> maximumWeight(int n, vector<vector<int>>& edges, int q, vector<int>& queries) {
        vector<int> parent(n + 1), sz(n + 1), res;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        
        vector<pair<int, pair<int, int>>> wt;
        for (auto& edge : edges)
            wt.push_back({edge[2], {edge[0], edge[1]}});
        
        sort(wt.begin(), wt.end());
        
        map<int, int> mp;
        for (auto& edge : wt) {
            int a = edge.first;
            int b = edge.second.first;
            int c = edge.second.second;
            mp[a] = Union(b, c, parent, sz, ans);
        }
        
        for (int i = 0; i < q; i++) {
            auto val = mp.upper_bound(queries[i]);
            if (val == mp.begin())
                res.push_back(0);
            else {
                val--;
                res.push_back(val->second);
            }
        }
        return res;
    }
    
private:
    int root(int i, vector<int>& parent) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    int Union(int a, int b, vector<int>& parent, vector<int>& sz, int& ans) {
        int ra = root(a, parent);
        int rb = root(b, parent);
        if (ra == rb)
            return sz[ra] * sz[ra];
        if (sz[ra] < sz[rb]) {
            swap(ra, rb);
            swap(a, b);
        }
        ans += sz[ra] * sz[rb];
        parent[rb] = ra;
        sz[ra] += sz[rb];
        return ans;
    }
};




//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends
