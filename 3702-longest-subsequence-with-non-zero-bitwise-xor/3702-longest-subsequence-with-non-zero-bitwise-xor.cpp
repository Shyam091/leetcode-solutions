class Solution {
public:

    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        int count = 0;
    
        for(int i=0;i< nums.size();i++)
        {
            ans^=nums[i];
            if(nums[i] == 0)
            {
                count++;
            }
        }
        if(count == nums.size())
        {
            return 0;
        }
        return ans == 0 ? nums.size()-1 : nums.size();
    }
};