class Solution {
public:
    vector<string>ans;
    void dpp(int n,int cnt,string s)
    {
        if(n==0 && cnt==0) 
        {
            ans.push_back(s);
            return;
        }
        if(n>0)
        {
            s.push_back('(');
            dpp(n-1,cnt+1,s);
            s.pop_back();
        }
        if(n>0 && cnt>0)
        {
            s.push_back(')');
            dpp(n-1,cnt-1,s);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string s;
        dpp(2*n,0,s);
        return ans;
    }
};