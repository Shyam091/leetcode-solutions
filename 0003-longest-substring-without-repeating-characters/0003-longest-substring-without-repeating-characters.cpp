class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>lastSeen;
        int n=s.size();
        if(n == 0)
        {
            return 0;

        }
        if(n==1)
        {
            return 1;
        }
        int left=0;
        int Max=0;
        
        for(int r=0;r<n;r++)
        {
            
            if(lastSeen.find(s[r])!=lastSeen.end() && lastSeen[s[r]]<r && lastSeen[s[r]] >= left)
            {
                Max = max(Max, r-lastSeen[s[r]]);

                left = lastSeen[s[r]]+1;
                
            }
            else{
            Max=max(Max,r-left+1);
            }

            lastSeen[s[r]]=r;
        }
    
        return Max;
        
    }
};