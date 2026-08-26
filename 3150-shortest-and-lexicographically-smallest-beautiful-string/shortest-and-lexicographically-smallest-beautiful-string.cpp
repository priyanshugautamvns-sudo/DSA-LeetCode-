class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0;
        int j=0;
        int sum=0;
        sum+=s[i]-'0';
        while(j<s.size())
        {
            if(sum<k)
            {
                j++;
                if(j<s.size()) sum+=s[j]-'0';
            }
            else if(sum==k)
            {
                while(s[i]-'0'==0)
                {
                    i++;
                }
                if(pq.empty()||j-i+1<=pq.top().first)
                {
                    pq.push({j-i+1,i});
                }
                j++;
                if(j<s.size()) sum+=s[j]-'0';
            }
            else
            {
                // while(sum>=k)
                // {
                    sum-=(s[i]-'0');
                    i++;
                // }
                // i--;
                // sum+=s[i]-'0';
            }
        }
        if(pq.empty()) return "";
        int a1=pq.top().first;
        string ans=s.substr(pq.top().second,a1);
        pq.pop();
        while(!pq.empty())
        {
            int b1=pq.top().first;
            string b2=s.substr(pq.top().second,b1);
            pq.pop();
            if(a1==b1)
            {
                ans=min(ans,b2);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};