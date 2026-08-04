class Solution {
public:
    int fib(int n) {
        int p1=0;
        int p2=1;
        int cur;
        if(n==0)return 0;
        if(n==1)return 1;
        for(int i=2;i<=n;i++)
        {
            cur=p2+p1;
            p1=p2;
            p2=cur;
        }
        return cur;
    }
};