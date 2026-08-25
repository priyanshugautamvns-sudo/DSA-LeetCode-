class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int>pre(stones.size());
        int n=stones.size();
        pre[0]=stones[0];
        for(int i=1;i<stones.size();i++){
           pre[i]=pre[i-1]+stones[i];
        }

        int x=pre[n-1];
        for(int i=n-2;i>=1;i--){
            x=max(x,pre[i]-x);
            
        }
        return x;

    }
};