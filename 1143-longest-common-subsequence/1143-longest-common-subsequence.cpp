int findLongest(int idx1,int idx2,vector<vector<int>>& dp,string& text1,string& text2,string& res)
{
    if(idx1==text1.length() || idx2==text2.length())
        return 0;

    if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];

    if(text1[idx1]==text2[idx2])
    {
        res+=text1[idx1];
        return dp[idx1][idx2]=1+findLongest(idx1+1,idx2+1,dp,text1,text2,res);
    }
    else
    {

        int left = findLongest(idx1+1,idx2,dp,text1,text2,res);
        int right = findLongest(idx1,idx2+1,dp,text1,text2,res);

        return dp[idx1][idx2]=max(left,right); 
    }       
}




class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int  idx1= 0;
        int idx2 = 0;

        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,-1));
       
        string res="";

        int f=findLongest(idx1,idx2,dp,text1,text2,res);
        cout << res;
        return f;
    }
};