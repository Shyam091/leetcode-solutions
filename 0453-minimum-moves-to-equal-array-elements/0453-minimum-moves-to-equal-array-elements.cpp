class Solution {
public:
    int  minMoves(vector<int>& nums) {
        long long total_sum  = accumulate(nums.begin(), nums.end(), 0LL);
        long long mn = *min_element(nums.begin(),nums.end());

        return total_sum - (  mn * nums.size());
    }
};