class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int Min = *min_element(nums.begin(), nums.end());
        int Max = *max_element(nums.begin() , nums.end());
        unordered_map<int, int>mp;
        int n = nums.size();
        vector<int>ans;
        for(int x:nums)
        {
            mp[x]++;
        }
        for(int i=Min+1;i<Max;i++)
        {

         if(mp.find(i) == mp.end())
         {
            ans.push_back(i);
         }
        }
        return ans;
    }
};