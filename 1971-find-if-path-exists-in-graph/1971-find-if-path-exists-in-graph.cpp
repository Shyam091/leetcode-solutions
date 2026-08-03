class Solution {
public:
    vector<int>nodes;
    bool find( vector<vector<int>>& adj, int node,  int destination)
    {
        nodes[node] = 1;
        if(node ==  destination)
        {
            return true ;
        }
        for(int neigh : adj[node])
        {
            if(!nodes[neigh] && find(adj,neigh, destination )  )
            {
                    return true ;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        nodes.assign(n,0);
        vector<vector<int>>adj(n);
        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = find(adj, source,   destination);
        return ans;

    }
};