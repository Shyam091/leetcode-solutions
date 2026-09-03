

class Solution {
public:
    vector<vector<int>>vis;

    bool checkExist(vector<vector<char>>&board, string& word, int i, int j, int n, int m,  int ind)
    {
            if(i>=n || i < 0 || j>=m || j<0)
            {
                return false;
            }

         if(vis[i][j] ||  word[ind] != board[i][j])
         {
            return false;
         }
            if(ind == word.size()-1)
            {
                return true;
            }

       


            vis[i][j]=1;
        bool ans =
            checkExist(board, word,i-1,j,n,m,  ind+1 ) || // up 
            checkExist(board, word, i, j+1, n,m, ind+1) || // right 
            checkExist(board, word, i+1, j, n, m, ind+1) || // down
            checkExist(board, word, i, j-1, n, m, ind+1); // left
            vis[i][j]=0;
         

         
 


         return ans  ;
    }
    bool exist(vector<vector<char>>& board, string word) {

        
        int n = board.size();
        int m = board[0].size();
        vis.assign(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              
                if(word[0] == board[i][j] &&  checkExist(board, word, i, j, n, m , 0) )
                {
                    return true ;
                }
             
            }
        }

        return false;
    }
};
