class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        
        vector<int> nextBig(n, n);

     
        vector<vector<int>> covered(n);

        
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) nextBig[i] = st.top();
            st.push(i);
        }

        st = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (!st.empty()) covered[st.top()].push_back(i);
            st.push(i);
        }

        long long ans = 0;
        long long cost = 0;
        int left = 0;
        deque<int> dq;   

        for (int right = 0; right < n; right++) {
       
            if (!dq.empty()) {
                cost += max(0, nums[dq.front()] - nums[right]);
            }
            while (!dq.empty() && nums[dq.back()] <= nums[right]) dq.pop_back();
            dq.push_back(right);

     
            while (cost > k) {
                if (dq.front() == left) dq.pop_front();

                for (int p : covered[left]) {
                    if (p > right) break;
                    int end = min(nextBig[p], right + 1);
                    cost -= 1LL * (end - p) * (nums[left] - nums[p]);
                }
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};