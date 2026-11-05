class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int ans = 0;
        
        sort(arr2.begin() , arr2.end());

        for(int i=0;i<n;i++)
        {
            int l = arr1[i] - d;
            int r = arr1[i] + d;
            int left = 0;
            int right = m-1;
            bool found =  false ;

            while(left<=right)
            {
                int mid = (left + right) / 2;
                if(arr2[mid] <= r && arr2[mid] >= l )
                {
                    found = true ;
                    break ;
                }
                else if(arr2[mid] > r )
                {
                    right = mid - 1;
                }

                else if(arr2[mid] < l)
                {

                    left = mid + 1;
                }

            }     

            if(!found) ans++;   
        }
        return ans ;
    }
};