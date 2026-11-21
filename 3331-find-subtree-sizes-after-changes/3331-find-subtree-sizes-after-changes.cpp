class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> newParent(parent);
        vector<int> last(26, -1);

        vector<int> saved(n, -1);
        vector<pair<int,int>> st;
        st.push_back({0, 0});

        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();
            int c = s[u] - 'a';

            if (state == 0) {
                if (u != 0 && last[c] != -1) {
                    newParent[u] = last[c];
                }
                saved[u] = last[c];
                last[c] = u;

                st.push_back({u, 1});
                for (int v : children[u]) {
                    st.push_back({v, 0});
                }
            } else {
                last[c] = saved[u]; 
            }
        }

        vector<vector<int>> newChildren(n);
        for (int i = 1; i < n; i++) {
            newChildren[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> order;
        order.reserve(n);
        vector<int> stk;
        stk.push_back(0);
        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();
            order.push_back(u);
            for (int v : newChildren[u]) {
                stk.push_back(v);
            }
        }
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};