class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i] , i});
        }
        int left = 1;
        auto [val , ind] = pq.top();
        ans.push_back(val);
        if(ind < left)
        {
            pq.pop();
        }

        for(int i=k;i<n;i++)
        {
            pq.push({nums[i] , i});
            auto [value , index] = pq.top();
            if(index < left)
            {
                while(index < left)
                {
                    pq.pop();
                    tie(value , index) = pq.top();
                }
            }
            ans.push_back(value);
            left++;
        }
        return ans;
    }
};