class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<nums.size();i++)
        {
            if(pq.size() == k)
            {
                pq.push(nums[i]);
                pq.pop();
            }
            else{
                pq.push(nums[i]);
            }
        }
        
    }
    
    int add(int val) {
        if(pq.size() == k)
        {
            pq.push(val);
            pq.pop();
            return pq.top();
        }
        else{
            pq.push(val);
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */