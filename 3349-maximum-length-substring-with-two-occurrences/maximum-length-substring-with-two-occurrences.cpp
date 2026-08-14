class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        map<char,int>mp;
        int ms=0;
        while(j<s.size())
        {
            if(mp[s[j]]<2)
            {
                ms=max(ms,j-i+1);
                mp[s[j]]++;
                j++;
            }
            else
            {
                mp[s[i]]--;
                i++;
            }
        }
        return ms;
    }
};