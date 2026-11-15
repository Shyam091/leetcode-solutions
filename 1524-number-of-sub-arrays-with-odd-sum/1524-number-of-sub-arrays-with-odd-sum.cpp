class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        long long odd = 0, even = 1, res = 0;
        int p = 0;

        for (int x : arr) {
            p ^= (x & 1);
            if (p) {
                res += even;
                odd++;
            } else {
                res += odd;
                even++;
            }
            res %= mod;
        }
        return (int)res;
    }
};