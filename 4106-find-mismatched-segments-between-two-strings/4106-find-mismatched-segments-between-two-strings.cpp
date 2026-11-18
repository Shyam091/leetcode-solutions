class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        string a = "";
        string b = "";
        vector<vector<string>>ans;
        int n = s1.size();
        int m = s2.size();

        for(int i=0;i<n;i++)
        {
            if(s1[i] != s2[i])
            {
                int j = i;
                while(j < n && s1[j] !=  s2[j]){
                    a += s1[j];
                    b += s2[j];
                    j++;
                     }
                ans.push_back({a,b});
                a="";
                b="";
                    i = j;
            
        }
        }
        return ans;
      
    }
};