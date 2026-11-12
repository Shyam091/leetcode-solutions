class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int n = nums.size();
        int leftI = 0;
        int leftD = 0;

        for(int right = 1 ; right < n; right++)
        {
        
            if(nums[right-1] < nums[right])
            {
                inc = max(right - leftI + 1, inc);

            }
            else{
                leftI  = right ;
            }

            if(nums[right-1] > nums[right])
            {
                dec = max(right - leftD + 1, dec);
            }
            else{
                leftD =  right ;
            }

        
        
    }
    
        return max(inc , dec);
        
    }
};