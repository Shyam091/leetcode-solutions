class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int ans = 0;
        bool flag = false;

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (abs(arr1[i] - arr2[j]) > d) {
                    if (j == 0) {
                        ans++;
                    }
                }

                else {
                    break;
                }
            }

            if (flag) {
                break;
            }
        }

        return ans;
    }

    // 1,2,3,4
    // -4, -3, 6, 10, 20 ,30

    // 4 5 8 : 1 8 9 10
};