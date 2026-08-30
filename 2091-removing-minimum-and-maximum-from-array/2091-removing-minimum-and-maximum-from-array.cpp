class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minPos = 0, maxPos = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minPos])
                minPos = i;

            if (nums[i] > nums[maxPos])
                maxPos = i;
        }

     
        if (minPos > maxPos)
            swap(minPos, maxPos);

   
        int front = maxPos + 1;

       
        int back = n - minPos;

      
        int both = (minPos + 1) + (n - maxPos);

        return min({front, back, both});
    }
};