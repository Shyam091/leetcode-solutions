class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto it : points) {
            int x1 = it[0];
            int y1 = it[1];
            int x2 = 0;
            int y2 = 0;
            double result = sqrt(pow((x1 - x2), 2) + pow(y1 - y2, 2));
            if (pq.size() == k) {
                pq.push({result, {x1, y1}});
                pq.pop();
            } else {
                pq.push({result, {x1, y1}});
            }
        }
        while (!pq.empty()) {
            auto [val, pairAns] = pq.top();
            pq.pop();
            vector<int> v = {pairAns.first, pairAns.second};
            ans.push_back(v);
        }
        return ans;
    }
};