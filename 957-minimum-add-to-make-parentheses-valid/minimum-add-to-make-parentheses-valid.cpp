class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        st.push(s[0]);
        int i=1;
        while(i<s.size())
        {
            if(s[i]=='(') st.push(s[i]);
            else
            {
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(s[i]);
            }
            i++;
        }
        return st.size();
    }
};