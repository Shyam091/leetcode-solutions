class Solution {
public:
    string digitSum(string s, int k) {

        if(s.size() <= k) return s ;
        string afterRound = "";
        while (true) {
        int n = s.size();
        int val = 0;
            for (int i = 0; i < s.size(); i++) {
                val += s[i]-'0';

                if (i == n - 1) {
                    afterRound += to_string(val);
                    val = 0;
                }
                 else if ((i + 1) % k == 0) {
                        afterRound += to_string(val);
                        val=0;
                }
            }
            if ((int)afterRound.size() <= k) {
                return afterRound;
            }
            s = afterRound;
            afterRound = "";
        }

        return "";
    }
};