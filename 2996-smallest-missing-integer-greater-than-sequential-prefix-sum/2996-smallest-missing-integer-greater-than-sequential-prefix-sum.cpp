class Solution {
public:
    int missingInteger(vector<int>& nums) {
      int  n = nums.size();
      unordered_map<int,int>mp;
      for(int x:nums)
      {
        mp[x]++;
      }
      if(n == 1)
      {
        return nums[0]+1;
      }

      int pSum = nums[0];


      for(int i=1;i<n;i++)
      {
        if(nums[i] == nums[i-1]+1)
        {
            pSum+=nums[i];
        }
        else{
            break ;
        }


      }

      for(int i=pSum ; i<1e9+7;i++)
      {
        if(i>=pSum && mp.find(i) == mp.end())
        {
            return i;
        }
      }
    return pSum;

        
    }
};