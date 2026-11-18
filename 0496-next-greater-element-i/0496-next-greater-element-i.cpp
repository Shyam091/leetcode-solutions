class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans(n,-1);
        unordered_map<int,int>mp;
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            mp[nums1[i]]=i;
        }

        for(int i=m-1;i>=0;i--)
        {

            if(mp.find(nums2[i]) == mp.end()){ 
                st.push(nums2[i]);
                 continue ;
            }

          else  if(st.empty())
            {
                
            }
            else{
                    if(st.top() > nums2[i])
                    {
                            ans[mp[nums2[i]]]=st.top();
                            
                    }
                    else {

                        while(!st.empty() && st.top() < nums2[i])
                        {
                            st.pop();
                        }

                        if( st.empty())
                        {

                        }

                        else{
                            ans[mp[nums2[i]]]=st.top();
                        }
                       
            }
            }
            st.push(nums2[i]);
        }

        return ans;

    }
};