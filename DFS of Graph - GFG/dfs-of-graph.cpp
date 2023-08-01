//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[], vector<bool> &visited, int idx, vector<int> &ans)
{
    
    visited[idx] = 1;               // marking the current node as visited
    ans.push_back(idx);      /* as we visit a node for the first time we add it into our ans */
    
    /* we traverse therough the nodes connected to current node and that are        not yet visited */   
    for(int i=0;i<adj[idx].size();i++)
    {
        if (visited[adj[idx][i]] == 0)
        {
            dfs(adj, visited, adj[idx][i], ans); // recursive call
        }
    }
}
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
         vector<bool> visited(n, 0); // keeps track of all the visited nodes
         vector<int> ans;  // final ans vector
         dfs(adj, visited, 0, ans);
         
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends