class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     int n = nums.size();
     priority_queue<pair<int, int>>pq;
     vector<int>ans;

     for(int i=0;i<k;i++)
     {
        pq.push({nums[i] , i});
     }
     auto [val , ind] = pq.top();
     ans.push_back(val);
     int left = 1;
     if(ind < left)
     {
        pq.pop();
     }

     for(int i = k ; i < n ; i++)
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
        left++;
        ans.push_back(value);
     }
     return ans;
    }
};