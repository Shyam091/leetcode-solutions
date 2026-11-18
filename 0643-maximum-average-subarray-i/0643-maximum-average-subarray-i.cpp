class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0;
        long long val = 0;
        double ans = INT_MIN;
        for(int right = 0;right<n  ;right++)
        {
            val += nums[right];
            if(right - left +  1 == k)
            {
                ans =  max(double(ans), (double)val / k );
                val -= nums[left++];
            }
        }   

        return ans ;
    }
};