class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq1(256,-1);
        vector<int> freq2(256,-1);

        vector<int> res;

        int n = s.length();
        int m = p.length();
        if(m>n)
            return {};

        for (int i=0;i<m;i++)
        {
            freq1[s[i]-'a']++;
            freq2[p[i]-'a']++;
        }

        if(freq1==freq2)
            res.push_back(0);

        int left =0;

        for (int i=m;i<n;i++)
        {
            freq1[s[left]-'a']--;
            freq1[s[i]-'a']++;
            if(freq2==freq1)
                res.push_back(left+1);
            left++;    
        }

    return res;


    }
};