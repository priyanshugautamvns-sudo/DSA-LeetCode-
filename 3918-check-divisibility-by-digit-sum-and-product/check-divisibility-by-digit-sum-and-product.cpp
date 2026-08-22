class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int sum=0;
        int prd=1;
        for(int i=0;i<s.size();i++)
        {
            sum+=s[i]-'0';
            prd*=s[i]-'0';
        }
        int fin=prd+sum;
        return n%fin==0;
    }
};