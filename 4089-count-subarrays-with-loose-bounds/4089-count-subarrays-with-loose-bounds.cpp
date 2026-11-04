class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        long long ans = 0;
        long long  size=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i] >= minK && nums[i] <= maxK)
            {
             size++;   
             if(i == n-1)
             {
                ans += (size * (size+1))/2;
             }
            }

            else {
                ans += (size * (size + 1)) / 2;
                size= 0;
                }
                }
            

            // 1, 2, 3, 4
        

        return ans ;
    }
};