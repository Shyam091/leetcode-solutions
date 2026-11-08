class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans = 1;
        if(a.contains(b))
        {
            return ans ;
        }
        string A = a ;

        while(a.size() < b.size())
        {
            a+=A;
            ans++;
        }
        if(a.contains(b))
        {
            return ans;
        }

        a += A;
        ans++;
        if(a.contains(b)) return ans ;

        return -1 ;
    }
};