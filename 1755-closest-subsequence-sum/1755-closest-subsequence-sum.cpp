class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& sets, int n, int i, int sum) {
        if (i >= n) {
            sets.push_back(sum);
            return;
        }

        backtrack(nums, sets, n , i+1 , sum+nums[i]);
        backtrack(nums, sets, n , i+1 , sum);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> sets;
        vector<int> sets2;
        int ans = INT_MAX;
        backtrack(nums, sets, (n/2) , 0, 0);
        backtrack(nums , sets2, n, n/2,0);
        sort(sets2.begin() , sets2.end());

        for( int ele : sets)
        {
            int diff = goal - ele;
            
            auto it = lower_bound(sets2.begin() , sets2.end(), diff);
            
            // there are two conditions which we need to check;
            // use the curr pointer given by the lower_bound if not pointing to the sets2.end().
             if(it != sets2.end())
             {
                ans = min(ans, abs( (ele + *it) - goal) );
             }
             //2nd we check two conditons in one, 1 - if out iterator was pointing to the sets2.end()
             // 2-b value which is just behind the curr iterator could be closer than curr pointer returned by the lower_bound

             if(it != sets2.begin())
             {
                it--;
                ans = min(ans, abs( (ele+*it)-goal));
             }
         
        }

        
        return ans;
    }
};