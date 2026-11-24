#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int i = 0; i < n; i++) {
            long long p = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                p *= x;
                g = gcd(g, (long long)x);
                l = l / gcd(l, (long long)x) * x;
                if (p > 25200) break;  // lcm * gcd can never exceed 2520 * 10
                if (p == l * g) best = max(best, j - i + 1);
            }
        }
        return best;
    }
};