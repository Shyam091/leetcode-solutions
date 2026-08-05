class Solution {
public:
    vector<int >vis;
    vector<int>vis2;
    bool flag =  false ;
    void solve(vector<vector<int>>&adj , int node)
    {
        vis[node]=1;
        for(int neigh : adj[node])
        {

                if(!vis[neigh] )
                {
                    solve(adj, neigh);
                }
            
        }
    }
    void check(vector<vector<int>>&adj, int node)
    {
        vis2[node]=1;
        for(int neigh : adj[node])
        {

            if(vis[neigh])
            {
                flag = true ;
                return ;
            }
            else if(!vis2[node]){
                check(adj, neigh);
            }
            
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vis.assign(n,0);
        vector<vector<int>>adj(n);
        vis2.assign(n,0);
          vector<int>ans;
        for(auto conn : invocations)
        {
            adj[conn[0]].push_back(conn[1]); // 1->2 , 0->1 , 3->2
        }
        solve(adj,k);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                check(adj, i);
            }
        }
        if(flag)
        {
          
            for(int i=0;i<n;i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        else{
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
            }
};