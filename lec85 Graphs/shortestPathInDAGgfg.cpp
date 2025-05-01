//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void dfs(int node, stack<int> &s, unordered_map<int,bool> &visited,
    unordered_map<int, list<pair<int,int>>> &adj)
    {
        visited[node] = true;
        
        for(auto i : adj[node])
        {
            if(!visited[i.first])
            {
                dfs(i.first,s,visited,adj);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<pair<int,int>>>  adj;
        for(int i=0; i<E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            pair<int,int> p = make_pair(v,w);
            adj[u].push_back(p);
        }
        
        
        vector<int> dist(V);
        for(int i=0; i<V; i++)
        {
            dist[i] = INT_MAX;
        }
        dist[0] = 0;
        unordered_map<int,bool> visited;
        stack<int> s;
        dfs(0, s,visited,adj);
        
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            
            if(dist[top] != INT_MAX)
            {
                for(auto i: adj[top])
                {
                    if(dist[top] + i.second < dist[i.first]) 
                        dist[i.first] = dist[top] + i.second;
                }
            }
        }
        for(int i=0; i<dist.size(); i++)
        {
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends