class Solution {
public:
    int ans = INT_MAX;

    // for memoization we just need to memorize the current path result.
    vector<vector<int>>v;

    int backtrack(string& w1, string& w2, int n , int m, int i, int j)
    {
       if( i>=n )
       {
        return m-j;
       }

       if(j>=m)
       {
        return n-i;
       }

        if(v[i][j] == -1)
        {

        if(w1[i] == w2[j])
        {
            return v[i][j] = 0 + backtrack(w1, w2, n, m, i+1, j+1); // matched
        }
        else{ 

           return  v[i][j] = min({1+ backtrack(w1, w2, n, m, i, j+1)      ,1+ backtrack(w1,w2, n , m,i+1,j)   ,1+ backtrack(w1, w2, n, m , i+1, j+1) });
        }

        }

        return v[i][j];
    }
    int minDistance(string word1, string word2) {


    int n = word1.size();
    int m = word2.size();
    v.assign(n+1, vector<int>(m+1, -1));





    return backtrack(word1, word2, n , m, 0, 0);

    }
};