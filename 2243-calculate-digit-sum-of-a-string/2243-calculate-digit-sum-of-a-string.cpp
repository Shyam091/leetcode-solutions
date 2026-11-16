class Solution {
public:
    string digitSum(string s, int k) {

        if(s.size() <= k) return s ;
        int n = s.size();
        string afterRound = "";
        string ch = "";
        while (true) {
        int n = s.size();

            for (int i = 0; i < s.size(); i++) {
                ch += s[i]; // "1 1 1 1 1 2 2 2 2 2 3"

                if (i == n - 1) {
                    int val = 0;
                    for (int i = 0; i < ch.size(); i++) {
                        val += ch[i] - '0';
                    }
                    afterRound += to_string(val);
                    ch = "";

                }
                 else if ((i + 1) % k == 0) {

                        int val = 0;
                        for (int i = 0; i < ch.size(); i++) {
                            val += ch[i] - '0';
                        }
                        afterRound += to_string(val);
                    
                    ch = "";
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