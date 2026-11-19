class Solution {
public:
    int reverse(int x) {
        int num=x;
        long long reverse_num=0;
         if(num>0){
                while(num>0){
            int digit=num%10;
            reverse_num=reverse_num*10+digit;
            num/=10;
        //      if(pow(-2,31)>reverse_num && reverse_num>pow(2,31-1)){
        //     return reverse_num;
        // }
        }
        }
        else{
                    while(num<0){
            int digit=num%10;
            reverse_num=reverse_num*10+digit;
            num/=10;
        //      if(pow(-2,31)>reverse_num && reverse_num>pow(2,31-1)){
        //     return reverse_num;
        // }
        }
        }
        if(pow(-2,31)<reverse_num && reverse_num<=pow(2,31)-1){
            return reverse_num;
        }
     
     return 0;
        
    }
};