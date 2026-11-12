class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<long long> gain;

        for (int x : nums) {
            sum += x;
            string s = to_string(x);
            sort(s.rbegin(), s.rend());      // digits in descending order
            long long best = stoll(s);
            gain.push_back(best - x);
        }

        sort(gain.rbegin(), gain.rend());  // largest gain first
        for (int i = 0; i < k && i < (int)gain.size(); i++) {
            sum += gain[i];
        }
        return sum;
    }
};