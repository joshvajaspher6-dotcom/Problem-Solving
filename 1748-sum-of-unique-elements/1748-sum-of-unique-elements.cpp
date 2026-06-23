class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mpp;
        
        for (auto it : nums)
            mpp[it]++;
        
        int sum =0;
        
        for (auto[x,y]: mpp)
        {
             if(y==1)
                 sum+=x;
        }       
                    
        return sum;
    }
};