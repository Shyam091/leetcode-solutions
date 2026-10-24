class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // n = 100 - 10 ^ 4

        int n = nums.size();
        int ans = 0;

        for(int i = 0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i] == nums[j])
                {
                    ans ++;
                }
            }
        }

        return ans ;
    }
};