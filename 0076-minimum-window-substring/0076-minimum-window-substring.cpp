class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> need(256,0);
        vector<int>window(256,0);

        for( char c : t)
        {
            need[c]++;
        }

        int left = 0;
        int minLength = INT_MAX;
        int start = 0;
        int matched = 0;

        for(int right = 0 ; right < n ; right++)
        {
            window[s[right]]++;
            if(window[s[right]] <= need[s[right]] )
            {
                matched++;
            }
            while(matched == t.size())
            {
                if(minLength > right - left + 1)
                {
                    start = left ;
                }
                minLength = min(minLength , right - left + 1);
                // start =  left;

                window[s[left]]--;
                if(window[s[left]] < need[s[left]])
                {
                    matched--;
                }
                left++;
            }

        }

        return minLength == INT_MAX ? "" : s.substr(start , minLength);
    }
};