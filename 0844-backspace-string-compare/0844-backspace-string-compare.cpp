class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> st1;
        for (auto it: s)
        {
            if(it=='#' && !st.empty())
                st.pop();
            else if(it=='#')
                continue;
            else    
                st.push(it);    

        }
        for (auto it: t)
        {
            if(it=='#' && !st1.empty())
                st1.pop();
            else if(it=='#')
                continue;    
            else
                st1.push(it);    

        }
        return st==st1;
    }
};