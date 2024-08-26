//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void buildGraph(vector<vector<int>>& adj, string str1, string str2) {
        int len = min(str1.length(), str2.length());
        for (int i = 0; i < len; i++) {
            if (str1[i] != str2[i]) {
                adj[str1[i] - 'a'].push_back(str2[i] - 'a');
                break;
            }
        }
    }

    void topologicalSort(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                topologicalSort(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }

    string findOrder(string dict[], int n, int k) {
        vector<vector<int>> adj(k);
        for (int i = 1; i < n; i++) {
            buildGraph(adj, dict[i - 1], dict[i]);
        }
        stack<int> st;
        vector<bool> visited(k, false);
        for (int i = 0; i < k; i++) {
            if (!visited[i]) {
                topologicalSort(i, adj, visited, st);
            }
        }
        string order;
        while (!st.empty()) {
            order += (char)(st.top() + 'a');
            st.pop();
        }
        return order;
    }
};


//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
