class Solution {
public:
    int ans = INT_MAX;

    // now we are done with the memoization part, we need to now more optmized it, with tabulation method.
    // we will use a 2d vector. named dp.
    vector<vector<int>>dp;


    int minDistance(string word1, string word2) {


    int n = word1.size();
    int m = word2.size();
    dp.assign(n+1, vector<int>(m+1, 0));
    // for dp part, we need to know about the base case.

    //  there are two base cases,
    // 1 if word2 is travered - then return m-j(m = word2, j=current index at word2)
    // 2 if word1 is travered - vice vera.

    for(int i=0;i<n+1;i++)
    {
        
         dp[i][0]=i;

      
    }

    for(int j=0;j<m+1;j++)
    {
        dp[0][j]=j;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(word1[i-1] == word2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }

            else{
                dp[i][j]=min({1+dp[i][j-1], 1+dp[i-1][j-1], 1+dp[i-1][j]});
            }

        }
    }

        return dp[n][m];
    }








    
};