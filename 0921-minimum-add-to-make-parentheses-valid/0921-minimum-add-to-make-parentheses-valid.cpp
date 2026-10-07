class Solution {
public:
    int minAddToMakeValid(string s) {
            // calculation will not work, have to use stack

            // if s[i] == ), there must be a (  before to balance it.
            // count of op and cc should be balanced

            int n =  s.size();
            int opC = 0;
            int cC = 0;

            // will try with normal simulation, then will try with stack

            // using stack
            stack<char>st;
            int count=0;

            for(int i=0;i<n;i++)
            {
                if(s[i] == ')')
                {
                    if(st.empty())
                    {
                        count++;
                        
                        continue ;
                    }
                    else if(st.top() == ')'){
                        count++;
                        st.pop();
                        continue ;

                    }
                    else if(st.top() == '(')
                    {
                        st.pop();
                        continue ;

                    }
                }

                if(s[i] == '(')
                {
                    if(i == n-1)
                    {
                        count++;
                        continue ;
                    }
                    st.push(s[i]);

                }


            }

            return count+st.size();
    }
};