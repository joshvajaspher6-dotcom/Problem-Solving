class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int cnt =0;
        if(arr[0]!=1)
        {
            arr[0]=1;
            
        }
        int maxi =1;
        for (int i=1;i<n;i++)
        {
            if(abs(arr[i]-arr[i-1])<=1)
            {
                maxi = max(maxi,arr[i]);
                continue;
            }
            else
            {
                arr[i]=arr[i-1]+1;
                maxi=max(maxi,arr[i]);
              
            }
        }
            
        return maxi;
        
    }
};