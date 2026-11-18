class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
                if (st.empty()) {
                    return false;
                } else {
                    if (s[i] == '}') {
                        if (st.top() == '{') {
                            st.pop();
                            continue;
                        } else {
                            return false;
                        }
                    }
                    if (s[i] == ')') {
                        if (st.top() == '(') {
                            st.pop();
                            continue;
                        } else {
                            return false;
                        }
                    }
                    if (s[i] == ']') {
                        if (st.top() == '[') {
                            st.pop();
                            continue;
                        } else {
                            return false;
                        }
                    }
                }
            }
            else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};