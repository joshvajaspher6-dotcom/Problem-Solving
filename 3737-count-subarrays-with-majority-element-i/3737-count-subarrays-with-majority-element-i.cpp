class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int num =0;
        int n = nums.size();
        for (int i=0;i<nums.size();i++)
        {
                int cnt =0;
                int len =0;
            for (int j=i;j<n;j++)
            {
                if(nums[j]==target)
                    cnt++;
                int len =(j-i+1)/2;
                if(cnt> len)
                {
                    num++;
                }
            }
        }
        return num;
    }
};