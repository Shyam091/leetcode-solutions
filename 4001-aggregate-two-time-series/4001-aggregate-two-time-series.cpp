class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {
        int left = 0;
        int right = 0;
        int n = series1.size();
        int m = series2.size();

        vector<vector<int>> ans;

        while (left < n && right < m) {

            if (series1[left][0] == series2[right][0]) {
                ans.push_back(
                    {series1[left][0], series1[left][1] + series2[right][1]});
                left++;
                right++;
            }

            else if (series1[left][0] < series2[right][0]) {
                ans.push_back(
                    {series1[left][0], series1[left][1] + series2[right][1]});
                left++;
            } else {
                ans.push_back(
                    {series2[right][0], series1[left][1] + series2[right][1]});
                right++;
            }
        }

        while (left < n) {
            ans.push_back({series1[left][0], series1[left][1]});
            left++;
        }

        while (right < m) {
            ans.push_back({series2[right][0], series2[right][1]});
            right++;
        }

        return ans;
    }
};