class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push(s[i]);
            else
            {
                 if(!st.empty() && st.top()==')')
        {
            st.pop();
            if(!st.empty() && st.top()=='(') st.pop(); // matched
            else cnt++; // need '(' for this "))"
        }
        // case 2: top is '('
        else if(!st.empty() && st.top()=='(')
        {
            if(i+1<s.size() && s[i+1]==')')
            {
                st.pop();
                i++;
            }
            else
            {
                cnt++; // need 1 extra ')'
                st.pop();
            }
        }
        // case 3: empty
        else
        {
            if(i+1<s.size() && s[i+1]==')')
            {
                cnt++; // need '('
                i++;
            }
            else
            {
                cnt+=2; // need '(' and second ')'
            }
        }
            }
        }
        // int cnt=0;
        // while(!st.empty())
        // {
        //     if(st.top()=='(')
        //     {
        //         cnt+=2;
        //         st.pop();
        //     }
        //     else
        //     {
        //         st.pop();
        //         if(st.empty())
        //         {
        //             cnt+=2;
        //         }
        //         else if(st.top()==')')
        //         {
        //             st.pop();
        //             cnt++;
        //         }
        //         else
        //         {
        //             cnt+=2;
        //             st.pop();
        //         }
        //     }
        // }
        return cnt+(st.size()*2);
    }
};