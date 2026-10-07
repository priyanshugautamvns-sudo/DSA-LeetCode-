class Solution {
public:
vector<string>ans;
set<string>sett;
    void func(string &s,string &st,int i,int n,int cnt)
    {
        if(i==n)
        {
            if(cnt==0)
            {
                if(sett.count(st)==0)
                {
                    ans.push_back(st);
                    sett.insert(st);
                }
            }
            return;
        }
        if(s[i]=='(' || s[i]==')') func(s,st,i+1,n,cnt);

        if(s[i]=='(') cnt++;
        else if(s[i]==')') cnt--;

        if(cnt>=0)
        {
            st.push_back(s[i]);
            func(s,st,i+1,n,cnt);
            st.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        string st;
        func(s,st,0,n,0);
        int maxi=0;
        vector<string>fans;
        for(int i=0;i<ans.size();i++)
        {
            int siz=ans[i].size();
            maxi=max(maxi,siz);
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i].size()==maxi)
            {
                fans.push_back(ans[i]);
            }
        }
        return fans;
    }
};