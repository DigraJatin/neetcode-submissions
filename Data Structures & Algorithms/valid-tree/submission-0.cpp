class Solution {
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(int nei : adj[node]){
            if(nei == parent) continue;
            if(visited[nei]) return false;
            if(!dfs(nei, node, adj, visited));
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        // Check for cycle
        if (!dfs(0, -1, adj, visited))
            return false;

        // Check connectivity
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }

        return true;
    }
};
