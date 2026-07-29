class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>freqCount;
        vector<int>ans;

        for(int x:nums)
        {
            freqCount[x]++;
        }

        for(auto [element , count] : freqCount)
        {
            pq.push({count , element});
        }

        while(k>0)
        {
            auto [freq , element] = pq.top();
            ans.push_back(element);
            pq.pop();
            k--;
        }
        return ans;
        
    }
};