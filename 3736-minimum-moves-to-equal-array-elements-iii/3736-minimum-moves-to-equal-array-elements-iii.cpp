class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin() , nums.end());
        int ans = 0;

        for(int i = 0;i<n;i++)
        {
            if(nums[i] == mx) continue ;
            ans += mx - nums[i];
        }

        return ans ;
        
    }
};