class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3,0);
        int left=0;
        int count = 0;
      
        for (int right=0;right<s.length();right++)
        {
            last[s[right]-'a']++;

            while(last[0]>=1&& last[1]>=1&& last[2]>=1)
            {
                count+=(s.length()-right);
                last[s[left]-'a']--;
                left++;

            }
        }
      return count;  
    }
};