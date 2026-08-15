class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(int x:tasks)
        {
            mp[x]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        queue<pair<char, pair<int,int>> >q;
        int timer=0;

        while(!pq.empty() || !q.empty())
        {
            timer++;
            if(!q.empty() && q.front().second.second <=timer )
            {
                
                pq.push({q.front().second.first,q.front().first});
                q.pop();
            }
            if(!pq.empty())
            {
                auto [f1,c1]=pq.top();
                pq.pop();
                
                if(f1-1>0)
                {

                    q.push({c1,{f1-1,timer+n+1}});
                }
            }
        }
        return timer;
    }
};