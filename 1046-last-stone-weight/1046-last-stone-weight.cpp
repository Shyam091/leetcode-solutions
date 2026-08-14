class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int x : stones)
        {
            pq.push(x);
        }
        while(!pq.empty())
        {
            int n1=pq.top();
            pq.pop();
            if(pq.empty())
            {
                return n1;
            }
            int n2 =  pq.top();
            pq.pop();
            if(n1 > n2)
            {
                pq.push(n1-n2);
            }
            else if(n2>n1)
            {
                pq.push(n2-n1);
            }
            // if they are same then do not push.
        }
        return 0;
    }
};