class Solution {
public:
    int largestInteger(int n, int s) {
        // greedy approach

        // pick 9 until we can(take the minimum between sum and 9.)
        string ans = "" ;
        for(int i = 0; i< n ;i++)
        {
            int digit = min(9 , s);
            ans += to_string(digit);
            s-= digit ;
            
        }
        if(s == 0)
        {
            return stoi(ans);
        }

        return -1;
        
    }
};