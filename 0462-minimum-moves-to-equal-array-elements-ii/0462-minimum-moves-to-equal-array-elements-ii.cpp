class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = (n - 1) / 2;
        int ans = 0;
        int target = nums[mid];
        for (int i = 0; i < mid; i++) {
            ans += nums[mid] - nums[i];
        }

        for (int i = mid + 1; i < n; i++)
        {
            ans+= nums[i] - nums[mid];
        }
        return ans ;
    }
};