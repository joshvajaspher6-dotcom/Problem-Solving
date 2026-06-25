class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int capacity = 2;
        int left = 0;
        int right = 0;
        int maxCount =0;

        int len = fruits.size();

        while(right < len && left < len)
        {
            mpp[fruits[right]]++;
            while(mpp.size()>2)
            {
                mpp[fruits[left]]--;

                if(mpp[fruits[left]]==0)
                {
                    mpp.erase(fruits[left]);
                }

                left++;

            }
            maxCount = max(maxCount,right-left+1);
            right++;
        }
        return maxCount;
    }
};