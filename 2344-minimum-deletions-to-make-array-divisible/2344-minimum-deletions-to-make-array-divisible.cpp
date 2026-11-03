class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
    int n = numsDivide.size();
    sort(nums.begin() , nums.end());
 
    int ans = numsDivide[0];

    for(int i = 1; i < n; i++) {
        ans = gcd(ans, numsDivide[i]);
    }
    int count = 0;


    for(int i=0;i<nums.size();i++)
    {

        count++;
        if(ans %  nums[i] == 0)
        {
            return count-1 ;
        }
    }

    return -1;
}
    
};