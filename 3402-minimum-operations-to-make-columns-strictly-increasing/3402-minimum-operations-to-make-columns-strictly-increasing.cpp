class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j!=0 && grid[j][i] < grid[j-1][i] )
                {
                    int x = grid[j-1][i] - grid[j][i];
                    ans+=(x+1);
                    grid[j][i] +=(x+1);
                    continue ;

                }

                else if( j!=0 && grid[j][i] == grid[j-1][i])
                {
                    ans+=1;
                
                    grid[j][i]++;
                }
            }
        }

        return ans ;
    }
};