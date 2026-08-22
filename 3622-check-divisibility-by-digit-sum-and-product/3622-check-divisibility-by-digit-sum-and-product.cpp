class Solution {
public:
    bool checkDivisibility(int n) {
        int m=n;

        int sum = 0;
        int product = 1;
        // 99
        // - 9) , -9)
        while(m>0)
        {
            sum+=(m%10); // 99 % 10 = 9;
            product*=(m%10);
            m/=10;
        }

        return !(n%(sum+product)); 

    }
};