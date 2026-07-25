class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<int>posSign;
        vector<int>negSign;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                posSign.push_back(i);
            }

        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                negSign.push_back(i);
            }
        }
        int posNum = 0;
        int negNum = 0;

        ans.push_back(nums[posSign[0]]);
        posNum++;
            while(negNum < negSign.size() || posNum < posSign.size())
            if(ans.back()>0)
            {
                ans.push_back(nums[negSign[negNum++]]);
              
            }

            else{
                ans.push_back(nums[posSign[posNum++]]);
            
            }
        
        

    return ans;
    }

};