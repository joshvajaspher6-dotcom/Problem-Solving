class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int i=0;
        int j = n-1;
        int maxi =INT_MIN;
        
        while(i<j)
        {
            int length= min(height[i],height[j]);
            int breadth = j-i;
            maxi= max(maxi,length*breadth);
            if(height[i]<height[j])
            {
                i++;
            }
            else
                j--;
        }
        return maxi;
    }
};