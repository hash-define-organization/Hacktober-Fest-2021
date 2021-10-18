#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int u, bool vis[], stack<int> &s, vector<int> adj[]) {
      vis[u] = true;
      for(auto v: adj[u]) {
        if(!vis[v]) {
          dfs(v, vis, s, adj);
        }
     }
    s.push(u);
    }

  void revDfs(int u, bool vis[], vector<int> adj[]) {
    vis[u] = true;
    for(auto v: adj[u]) {
      if(!vis[v]) {
        revDfs(v, vis, adj);
      }
    }
  }

  int kosaraju(int V, vector<int> adj[]) {
    bool vis[V] = {false};
    stack<int> s;

    for(int i = 0; i < V; i++) { // sort dfs according to finish time
      if(!vis[i]) {
        dfs(i, vis, s, adj);
      }
    }

    vector<int> tg[V];

    for(int i = 0; i < V; i++) { // transpose the graph(revese all directions)
      for(auto x : adj[i]) {
        tg[x].push_back(i);
        }
     }

    memset(vis, false, sizeof vis);

    int comp = 0;

    while(!s.empty()) {// tranverse the transposed graph and count components
      int x = s.top();
      s.pop();
      if(!vis[x]) {
        comp++;
        revDfs(x, vis, tg);
      }
    }

  return comp;
  }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
