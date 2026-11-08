class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n = s1.size();
        bool flag = true ;
        int right = 0;
        int lastLeft = -1;

        for (; right < n; right++) {
            if (s1[right] == s2[right] && lastLeft != -1) {
                int left = lastLeft;
                lastLeft = -1;
                string str = s1.substr(left, right - left);
                string str2 = s2.substr(left, right - left);
                left = right + 1;
                ans.push_back({str, str2});
            }

            else if (s1[right] != s2[right] && lastLeft == -1) {
                lastLeft = right;

                if (right == n - 1) {
                    flag = false ;
                    string str = s1.substr(right, 1);
                    string str2 = s2.substr(right, 1);
                    ans.push_back({str, str2});
                }
            }

            else  if (flag && s1[right] != s2[right] && lastLeft != -1 && right == n - 1) {
                    int left = lastLeft;

                    string str = s1.substr(left, right - left + 1);
                    string str2 = s2.substr(left, right - left + 1);

                    ans.push_back({str, str2});
                }
        }

        return ans;
    }
};