class Solution {
public:
    int countCommas(int n) {
        string s=to_string(n);
        int si=s.size();
        if(si<4) return 0;
        else if(si==4) return n-1000+1;
        else if(si==5) return 9000+n-9999;
        return 9000+n-9999;
    }
};