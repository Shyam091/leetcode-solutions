class Solution {
public:

    vector<vector<int>>vis;
    

    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int k)
    {
        if(i>=n || i<0 || j>=m || j<0)
        {
            return 0;
        }

        if(grid[i][j] == 0 || vis[i][j] == 1)
        {
            return 0;
        }

        int fans = 0 ;
        int val = grid[i][j];


            vis[i][j] = 1;
            grid[i][j]=0;
            
            
            fans =( (val % k ) +  (dfs(grid, i-1, j, n, m, k )%k) + 
           ( dfs(grid, i, j+1, n, m, k) % k ) +
           ( dfs(grid, i+1, j, n, m, k) % k) + 
            (dfs(grid, i, j-1, n, m, k) % k) % k);

        

        return fans;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vis.assign(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                
                if(grid[i][j] != 0)
                {
                    int ans = dfs(grid, i, j, n, m, k);
     
                    if(ans % k == 0)
                    {
                        count++;
                    }
            }
        }

       
    }
     return count;
    }
};