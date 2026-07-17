class Solution {
public:
    vector<int> vis;

    void solve(vector<vector<int>>& adj, int node, int destination) {
        vis[node] = 1;

        if (node == destination) {
            return;
        }

        for (int neighbour : adj[node]) {
            if (!vis[neighbour]) {
                solve(adj, neighbour, destination);
            }

            if (vis[destination]) {
                return;
            }
        }
    }

    bool validPath(
        int n,
        vector<vector<int>>& edges,
        int source,
        int destination
    ) {
        vector<vector<int>> adj(n);
        vis.assign(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve(adj, source, destination);

        return vis[destination];
    }
};