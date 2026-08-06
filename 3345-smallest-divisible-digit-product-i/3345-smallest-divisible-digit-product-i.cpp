class Solution {
public:
    int smallestNumber(int n, int t) {
        int nums=1;
        int m = n;
        while(m>0)
        {
            nums=(m%10)*nums;
            m/=10;
        }
        if(nums % t == 0)
        {
            return n;
        }


        while(nums % t !=0 )
        {
            nums=1;
            m=n;
        while(m>0)
        {
            nums=(m%10)*nums; // 1*5=5
            m/=10;
        }
        n++;
        }
        return n-1;
    }
};