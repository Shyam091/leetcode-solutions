class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            }
            else if (s[i] == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (isValid(cur)) {
                ans.push_back(cur);
                found = true;
            }

            if (found)
                continue;

            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] != '(' && cur[i] != ')')
                    continue;

                string temp = cur.substr(0, i) + cur.substr(i + 1);

                if (visited.find(temp) == visited.end()) {
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }

        return ans;
    }
};