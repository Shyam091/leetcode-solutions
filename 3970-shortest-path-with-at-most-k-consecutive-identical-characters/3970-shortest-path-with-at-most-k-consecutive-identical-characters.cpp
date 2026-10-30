class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) adj[e[0]].push_back({e[1], e[2]});

        const long long INF = LLONG_MAX;
     
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<tuple<long long,int,int>,
                       vector<tuple<long long,int,int>>,
                       greater<>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, run] = pq.top();
            pq.pop();

            if (d > dist[u][run]) continue;  
            if (u == n - 1) return (int)d;      

            for (auto [v, w] : adj[u]) {
                int newRun = (labels[v] == labels[u]) ? run + 1 : 1;
                if (newRun > k) continue;   

                if (d + w < dist[v][newRun]) {
                    dist[v][newRun] = d + w;
                    pq.push({dist[v][newRun], v, newRun});
                }
            }
        }
        return -1;
    }
};