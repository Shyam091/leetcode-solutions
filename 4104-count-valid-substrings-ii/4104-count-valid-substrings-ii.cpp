class Solution {
public:
    long long countValidSubstrings(string s) {
     int n=s.size();
     long long ans = 0;
     int left = 0;
     int right = 0;
     int lastA = -1;
     int lAforB = -1;
     
     for(; right < n ;right++)
     {
        if(s[right] == 'a')
        {
            lastA = right;
        }
        if(s[right] == 'b' && lastA != -1)
        {
            lAforB = lastA ;
        }
        if(s[right] == 'c' && lAforB != -1)
        {
            left= lAforB+1;
        }
        ans += right - left + 1;
     }   
        return ans ;
    }
};