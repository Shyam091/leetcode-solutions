class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        int n = s.length();
        int len = 10;
        int base = 5;

        if (n <= len)
            return {};

        auto getValue = [](char c) {
            if (c == 'A') return 1;
            if (c == 'C') return 2;
            if (c == 'G') return 3;
            return 4; // T
        };

    
        long long highestPower = 1;

        for (int i = 1; i < len; i++) {
            highestPower *= base;
        }

        unordered_set<long long> seen;
        unordered_set<string> repeated;

       
        long long hash = 0;

        for (int i = 0; i < len; i++) {
            hash = hash * base + getValue(s[i]); // same like 123
        }

        seen.insert(hash);

      
        for (int i = len; i < n; i++) {

            char outgoing = s[i - len];
            char incoming = s[i];

        
            hash -= getValue(outgoing) * highestPower;

           
            hash = hash * base + getValue(incoming);

         
            if (seen.count(hash)) {
                repeated.insert(s.substr(i - len + 1, len));
            }
            else {
                seen.insert(hash);
            }
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};