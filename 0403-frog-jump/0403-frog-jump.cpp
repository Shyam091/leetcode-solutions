class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
      

        vector<vector<int>> dp(n, vector<int>(n, -1));
      

        unordered_map<int, int> stoneToIndex;
        for (int i = 0; i < n; ++i) {
            stoneToIndex[stones[i]] = i;
        }
      
  
        function<bool(int, int)> dfs = [&](int currentIndex, int lastJumpSize) -> bool {

            if (currentIndex == n - 1) {
                return true;
            }
          

            if (dp[currentIndex][lastJumpSize] != -1) {
                return dp[currentIndex][lastJumpSize];
            }
          

            for (int nextJumpSize = lastJumpSize - 1; nextJumpSize <= lastJumpSize + 1; ++nextJumpSize) {
           
                if (nextJumpSize > 0) {
                    int nextPosition = stones[currentIndex] + nextJumpSize;
                  

                    if (stoneToIndex.count(nextPosition)) {
                        int nextIndex = stoneToIndex[nextPosition];
                        if (dfs(nextIndex, nextJumpSize)) {
                            return dp[currentIndex][lastJumpSize] = 1;
                        }
                    }
                }
            }
          

            return dp[currentIndex][lastJumpSize] = 0;
        };
      

        return dfs(0, 0);
    }
};
