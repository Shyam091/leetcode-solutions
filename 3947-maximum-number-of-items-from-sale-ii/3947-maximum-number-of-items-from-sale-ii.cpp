class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int maxF = 0;
        long long m = LLONG_MAX;
        for (auto &it : items) {
            maxF = max(maxF, it[0]);
            m = min(m, (long long)it[1]);
        }

        vector<int> cnt(maxF + 1, 0);
        for (auto &it : items) cnt[it[0]]++;

        vector<int> mult(maxF + 1, 0);
        for (int f = 1; f <= maxF; f++) {
            if (cnt[f] == 0) continue;
            long long s = 0;
            for (int k = f; k <= maxF; k += f) s += cnt[k];
            mult[f] = (int)s;
        }

        vector<pair<long long, long long>> v;
        v.reserve(n);
        for (auto &it : items) {
            long long d = mult[it[0]] - 1;
            if (d > 0) v.push_back({it[1], d});
        }
        sort(v.begin(), v.end());

        long long rem = budget, total = 0;
        for (auto &[p, d] : v) {
            if (p > 2 * m) break;
            if (p > rem) break;
            long long t = min(d, rem / p);
            total += 2 * t;
            rem -= t * p;
        }
        total += rem / m;
        return (int)total;
    }
};