class Solution {
public: 
    bool check=false;
    vector<vector<int>>vis;
    bool  dfs(vector<vector<char>>& board, string & word, int r, int c, int key)
    {
        if(key==word.size())
        {
            return true;
        }        
        if(r >=board.size() || c >= board[0].size( ) || vis[r][c]==1 || board[r][c]!=word[key])
        {
            return false;
        }
                vis[r][c]=1;//visited
        bool ans=false;
        ans=ans ||  dfs(board, word, r, c+1, key+1) ||dfs(board, word, r-1, c, key+1)
          ||  dfs(board, word, r+1, c, key+1)
          ||  dfs(board, word, r, c-1, key+1);   //lef
          vis[r][c]=-1;
          return ans;                   
   


    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int>path;
        vis.resize(board.size(), vector<int>(board[0].size(),-1));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(        dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }


        return false;
    }
};