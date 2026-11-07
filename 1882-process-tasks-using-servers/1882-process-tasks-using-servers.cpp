
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> free;
        
        priority_queue<pair<long long,pair<int,int>>,
        vector<pair<long long,pair<int,int>>>,
        greater<pair<long long,pair<int,int>>>> busy;

        int n = servers.size();

        for(int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        vector<int> ans;

        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {

            time = max(time, (long long)i);

      
            while(!busy.empty() && busy.top().first <= time) {

                auto x = busy.top();
                busy.pop();

                free.push(x.second);
            }

         
            if(free.empty()) {

                time = busy.top().first;

                while(!busy.empty() && busy.top().first <= time) {

                    auto x = busy.top();
                    busy.pop();

                    free.push(x.second);
                }
            }

         
            auto x = free.top();
            free.pop();

            ans.push_back(x.second);

            busy.push({time + tasks[i], x});
        }

        return ans;
    }
};
