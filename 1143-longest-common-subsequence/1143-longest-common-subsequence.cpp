class Solution {
public:
    vector<vector<int>>t;

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        t.assign(n+1, vector<int>(m+1, 0));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }

                else{
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }

        return t[n][m];
       
    }
};