class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         if(nums.size() == 1)
        {
            return nums[0];
        }
        priority_queue<int, vector<int>, greater<int>>pq;

        for(int x:nums)
        {
            if(pq.size() == k)
            {
                pq.push(x);
                pq.pop();
            }
            else{
            pq.push(x);
            }
        }
        return pq.top();
    }
};