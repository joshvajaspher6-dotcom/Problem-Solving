class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](const int &a, const int &b)
             {
                 
                 int l = __builtin_popcount(a);
                 int r = __builtin_popcount(b);
                 
                 if(l==r)
                 {
                     return a<b;
                 }
                 return l<r;
             });
        return arr;
    }
};