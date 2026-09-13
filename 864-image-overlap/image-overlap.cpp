class Solution {
public:
    int over(int i,int j,vector<vector<int>>& img1,vector<vector<int>>& img2,int sz)
    {
        int ans=0;
        for(int a=0;a<sz;a++)
        {
            for(int b=0;b<sz;b++)
            {
                if(a+i<=sz-1 && a+i>=0 && b+j<=sz-1 && b+j>=0 && img1[a+i][b+j]==1 && img2[a][b]==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int sz=img1.size();
        int overlap=INT_MIN;
        for(int i=-(sz-1);i<sz;i++)
        {
            for(int j=-(sz-1);j<sz;j++)
            {
                overlap=max(overlap,over(i,j,img1,img2,sz));
            }
        }
        return overlap;
    }
};