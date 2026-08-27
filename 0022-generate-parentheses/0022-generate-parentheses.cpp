class Solution {
public:

    vector<string>ans;

    void backtrack(int n , string s, int oC , int cC)
    {
        if(s.size() == 2*n)
        {
            ans.push_back(s);
            return ;
        }

        if(oC < n )
        {
            backtrack(n, s+"(", oC+1, cC); // pick '('
        }

        if(cC < n && oC >= cC+1)
        {
            backtrack(n,s+")",oC, cC+1); // pick ')'
        }
    }
    vector<string> generateParenthesis(int n) {


    //     start with the ( -> keep picking it until we hit n count of (.
    //     then start back tracking and pick ) with condition opening count >= closing count + 1, and cC < n
    // do check +1 before adding it to pair
    // example - "(())"
    // in the above example suppose n is three and we have to now pick ')' then we have to check first (cC +1 == 3) > oC(2), we will not pick this one.
    // because it will lead to "(()))", which is not balanced.


    // {n, string, ( : count, ):count}
    backtrack(n, "",  0, 0);
    return ans ;
    }

};
