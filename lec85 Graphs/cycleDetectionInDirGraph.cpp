#include<unordered_map>
#include<list>
#include<bits/stdc++.h>

//using dfs bfs

bool detectCycle(int node, unordered_map<int, bool> &visited,
                unordered_map<int ,bool> &dfsVisited, unordered_map<int, list<int>> &adj)
                {
                  visited[node] = true;
                  dfsVisited[node] = true;

                  for(auto v: adj[node]) //for all element belongs to adj[node]
                  {
                    if(!visited[v]){
                      bool cycleDetected = detectCycle(v, visited,dfsVisited, adj);
                      if(cycleDetected)
                        return true;
                    }
                    else if(dfsVisited[v]){
                      return true;
                    }
                  }
                  dfsVisited[node] = false;
                  return false;
                }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

  // unordered_map<int, list<int>> adj;
  // for(int i=0; i<edges.size(); i++)
  // {
  //   int u = edges[i].first;
  //   int v = edges[i].second;

  //   adj[u].push_back(v);
  // } 

  // unordered_map<int, bool> visited;
  // unordered_map<int ,bool> dfsVisited;

  // for(int i=0; i<n; i++)
  // {
  //   if(!visited[i])
  //   {
  //     bool cycleFound = detectCycle(i, visited,dfsVisited, adj);
  //     if(cycleFound)
  //         return true;
  //   }
  // }
  // return false;

    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegree(n);
    for(auto i:adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    //0 indegree walo ko push kardo
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    int cnt = 0;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // increase count
        cnt++;

        //neighbour indegree update
        for(auto neighbour: adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if(cnt == n) // this will happen iff the graph is DAG that is, it is a 
    //topological sort. This shows cycle is not present, therefore return flase
      return false;
    else // invalid topological sort
      return  true;

}