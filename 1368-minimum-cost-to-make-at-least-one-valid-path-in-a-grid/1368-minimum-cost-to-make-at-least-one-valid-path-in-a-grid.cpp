class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;

        deque<pair<int, int>> dq;

        // direction array
        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};

        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [r,c] = dq.front();
            dq.pop_front();
            int i = r;
            int j = c;
            

            for (int k = 0; k < 4; k++) {
                int cost ;
                int d_r = i + x[k];
                int d_c = j + y[k];

                if (d_r >= 0 && d_r < n && d_c >= 0 && d_c < m) {
                    if (grid[i][j] == k + 1) {
                        cost = 0;
                    }
                    else{
                        cost = 1;
                    }


                

                if(dis[i][j] + cost < dis[d_r][d_c])
                {
                    dis[d_r][d_c] = cost+dis[i][j];

                    if(cost)
                    {
                        dq.push_front({d_r,d_c});
                    }
                    else{
                          dq.push_back({d_r,d_c});
                    }
                }
                }
            }
        }

        return dis[n-1][m-1];
    }
};