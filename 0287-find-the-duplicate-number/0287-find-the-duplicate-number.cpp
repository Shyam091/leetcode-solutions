class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();

        int start = 1;
        int end = n-1;

        while(start < end)
        {
            int mid = (start + end) / 2;
            int lessOrEqual = 0;
            for(int  i=0;i<n;i++)
            {
                if(nums[i]<=mid)
                {
                    lessOrEqual++;
                }
                
            }

            if( lessOrEqual <= mid)
            {
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        
        return start;
            
    }
};