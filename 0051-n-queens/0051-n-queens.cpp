class Solution {
public:
vector<vector<string>>f_ans;

    bool is_safe(int i, int j, vector<vector<char>>&s, int n)
    {
        //upward
        int x=i-1;
        int y=j;

        while(x>=0)
        {
            if(s[x][y]=='Q')
            {
                return false;
            }
            x-=1;
        }

        //left diagonal

         x=i-1;
         y=j-1;

         while(x>=0 && y>=0)
         {
            if(s[x][y]=='Q')
            {
                return false;
            }
            x-=1;
            y-=1;            
         }

         // right diagonal
         x=i-1;
         y=j+1;

         while(x>=0 && y<n)
         {
            if(s[x][y]=='Q')
            {
                return false;
            }
            x-=1;
            y+=1;
         }

         return true;

    }

    void ans(vector<vector<char>>&v, int n)
    {
        vector<string>st;
        for(int i=0;i<n;i++)
        {
            string str="";
            for(int j=0;j<n;j++)
            {
            
            str+=v[i][j];
            }
          
            st.push_back(str);
            str="";


        }
          f_ans.push_back(st);

    }
    void solve(int i, int n, vector<vector<char>>&a)
    {
        if(i==n)
        {
            ans(a, n);
        }
     for(int j=0;j<n;j++)
     {
        if(is_safe(i,j, a, n))
        {
            a[i][j]='Q';
            solve(i+1, n, a);
            a[i][j]='.';
        }
     }
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<char>> v(n, vector<char>(n, '.'));
        solve(0, n, v);
        return f_ans;
    }
};