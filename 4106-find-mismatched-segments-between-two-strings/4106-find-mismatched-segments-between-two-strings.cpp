class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        vector<vector<string>> ans;

        string str1 = "";
        string str2 = "";

        int n = s1.size();

        for (int i = 0; i < n; i++) {

            if (s1[i] != s2[i]) {
                str1 += s1[i];
                str2 += s2[i];
            }
            else {
                if (!str1.empty()) {
                    ans.push_back({str1, str2});

                    str1.clear();
                    str2.clear();
                }
            }
        }

        if (!str1.empty()) {
            ans.push_back({str1, str2});
        }

        return ans;
    }
};