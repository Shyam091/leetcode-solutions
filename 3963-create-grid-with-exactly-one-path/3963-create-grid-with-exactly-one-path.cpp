class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // m = rows
        // n = columns
        string s = "";
        for(int i = 0 ; i<n;i++)
        {
            s+="#"; // ### for n 3
        }
        vector<string>v(m, s);
        /*
            # # #
            # # #
        */


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j == 0)
                {
                    v[i][j] = '.';
                }

                 if(i == m-1)
                {
                    v[i][j] = '.';
                }
            }
        }

        return v;
    }
};