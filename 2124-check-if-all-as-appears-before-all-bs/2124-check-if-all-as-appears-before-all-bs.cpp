class Solution {
public:
    bool checkString(string s) {
        int lsb=-1;
        int n = s.size();
        if(n == 1)
        {
            return true ;
        }

        for(int i=0;i<n;i++)
        {
            if(s[i]== 'a')
            {
                if(lsb != -1)
                {
                    return false;
                }
        }
        else{
            lsb = i ;
        }
        }

        return true ;

    }
};