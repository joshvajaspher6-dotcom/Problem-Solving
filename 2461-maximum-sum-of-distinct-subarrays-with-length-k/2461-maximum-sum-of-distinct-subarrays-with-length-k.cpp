class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();

        unordered_map<int, int> mpp;
        long long left = 0;

        long long sum = 0;
       

       long long  maxi=0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];

            mpp[nums[i]]++;
            
        }
        if(mpp.size()==k)
        {
            maxi=max(maxi,sum);
        }

        for (int i = k; i < n; i++) {
            sum-=nums[left];
            mpp[nums[left]]--;
            if(mpp[nums[left]]==0)
            {
                mpp.erase(nums[left]);
            }
            
            left++;
            mpp[nums[i]]++;
            sum+=nums[i];

            if(mpp.size()==k)
                maxi = max(maxi,sum);
        }
        return maxi;
    }
};