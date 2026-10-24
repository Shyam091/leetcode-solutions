class Solution {
public:
    vector<vector<int>> vis;

    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m)
    {
        if(i>=n || i<0 || j>=m || j<0)
        {
            return ;
        }

        if(grid[i][j] == '1' && !vis[i][j] )
        {
            vis[i][j]=1;
            grid[i][j]='0';
            dfs(grid,i-1,j,n,m ); // up
            dfs(grid, i, j+1, n, m); // right
            dfs(grid,i+1, j, n, m); // down
            dfs(grid,i, j-1, n, m); // left
        }

        
    }

    int numIslands(vector<vector<char>>& grid) {
        // 
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vis.assign(n, vector<int>(m,0));

        for(int i = 0  ; i< n ;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j, n, m);
                }
            }
        }

        return ans ;
    }
};