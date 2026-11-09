class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int srcR = source[0];
        int srcC = source[1];

        int targetR = target[0];
        int targetC = target[1];
        if(srcR == targetR && srcC == targetC)
            {
            return 0;
            }  
        if((srcR+srcC) == (targetR + targetC) ) // diagonal
        {
            return 1;
        }

        if(srcR == targetR || srcC == targetC)
        {
            return 1;
        }

        if(abs(srcR -targetR) == abs(srcC - targetC))
        {
            return 1;
        }



        return 2;
        
    }
};