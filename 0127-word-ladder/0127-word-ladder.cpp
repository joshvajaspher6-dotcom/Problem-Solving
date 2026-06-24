class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;

        int cnt =0;

        q.push({beginWord,cnt+1});
        if(st.find(beginWord)!=st.end())
            st.erase(beginWord);

        while(!q.empty())
        {
            auto [word,cnt] = q.front();
            q.pop();

            if(word == endWord)
                return cnt;
            for (int i=0;i<word.length();i++)
            {
                for (char ch ='a'; ch <='z';ch++)
                {
                    string str = word;

                    str[i]=ch;
                    if(st.find(str)!=st.end())
                    {
                        q.push({str,cnt+1});
                        st.erase(str);
                    }
                }
            }
        }
        return 0;
    }
};