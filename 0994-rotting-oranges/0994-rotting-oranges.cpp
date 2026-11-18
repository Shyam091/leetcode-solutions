class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int fresh = 0;
            int minutes=0;
            queue<pair<int,int>>q;
            for(int i =0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j] == 2)
                    {
                        q.push({i,j});
                   
                    }
                    else if(grid[i][j] == 1)
                    {
                             fresh++;
                    }
                }
            }

            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};

            while(!q.empty() && fresh>0)
            {
                int size = q.size();
                while(size--){
                auto [i,j] = q.front();
                q.pop();


                for(int d=0;d<4;d++)
                {
                    int x = i+dx[d];
                    int y = j+dy[d];

                    if(x>=0 && y >= 0 && x<n && y < m && grid[x][y] == 1)
                    {
                        grid[x][y]=2;
                        q.push({x,y});
                        fresh--;
                    }
                }
                }
                minutes++;
            }

            return fresh == 0 ? minutes : -1 ;
    }
};