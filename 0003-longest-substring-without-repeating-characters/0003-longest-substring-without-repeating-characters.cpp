class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n == 0)
        {
            return 0;

        }
        if(n==1)
        {
            return 1;
        }
        int l=0;
        int Max=0;
        int leftMost=0;
        for(int r=1;r<n;r++)
        {

            for(int j=r-1;j>=leftMost;j--)
            {
                if(s[j] == s[r])
                {
                    Max = max(Max, r-j);
                    leftMost = j+1;
                    break;
                }
                if(j==leftMost)
                {
                 Max = max(Max, r-j+1);   
                }
            }
        }
    
        return Max;
        
    }
};