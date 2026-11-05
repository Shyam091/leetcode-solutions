class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int>v={-1,-1};
        long long mult = INT_MIN;
      for(int i=0;i<nums.size();i++)
      {
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j] == target && nums[i] > nums[j])
            {
                long long m =  nums[i]*nums[j];
                if(m>mult)
                {
                v = {i,j};
                mult = m;
                }
            }
            if(nums[i]+nums[j] == target && nums[i] < nums[j])
            {
                long long m =  nums[i]*nums[j];
                if(m>mult)
                {
                v = {j,i};
                mult = m;
            }            
        } 
      }
      }

      return v;
    }
};