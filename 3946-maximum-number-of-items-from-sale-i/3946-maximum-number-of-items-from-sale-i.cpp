class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<long long> gain(n, 0);
        long long minPrice = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, (long long)items[i][1]);
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    gain[i]++;
                }
            }
        }

        vector<long long> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int p = items[i][1];
            if (p > budget) continue;
            long long val = 1 + gain[i];
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b], dp[b - p] + val);
            }
        }

        long long ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / minPrice);
        }
        return (int)ans;
    }
};