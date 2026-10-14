class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9) return "";
        string ans(num,'0');
        int n=num;
        while(sum>0)
        {
            if(sum>=9)
            {
                ans[n-num]='9';
                sum-=9;
                num--;
            }
            else
            {
                ans[n-num]='0'+sum;
                sum=0;
                num--;
            }
        }
        return ans;
    }
};