class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {

            if(i == n-1 )
            {
                if(nums[i] ==1)
                {
                    count++;
                }

                ans = max(count, ans);
            }
            
         else if(nums[i] == 0)
            {
                ans = max(ans, count);
                count = 0;
            }
            else{
                count++;
            }
        }

        return ans;
    }
};