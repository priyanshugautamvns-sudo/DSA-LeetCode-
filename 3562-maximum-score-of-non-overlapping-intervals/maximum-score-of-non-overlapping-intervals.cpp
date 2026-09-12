class Solution {
public:
    int find(vector<vector<int>>& inter,int end,int i)
    {
        int high=inter.size()-1;
        int low=i+1;
        int res=inter.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(inter[mid][0]>end)
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }
    struct Node
    {
        long long weight=0;
        vector<int>ind;
    };
    Node solve(vector<vector<int>> &inter,vector<int>& nex,int index,int cnt,vector<vector<Node>>& dp,vector<vector<int>>& vis)
    {
        if(cnt==4 || index==inter.size()) return Node();
        if(vis[index][cnt]!=-1) return dp[index][cnt];
        Node nt=solve(inter,nex,index+1,cnt,dp,vis);
        Node t=solve(inter,nex,nex[index],cnt+1,dp,vis);
        t.weight=t.weight+inter[index][2];
        t.ind.push_back(inter[index][3]);
        sort(t.ind.begin(),t.ind.end());
        if(t.weight>nt.weight)
        {
            vis[index][cnt]=1;
            return dp[index][cnt]=t;
        }
        else if(t.weight<nt.weight)
        {
            vis[index][cnt]=1;
            return dp[index][cnt]=nt;
        }
        if(t.ind>nt.ind)
        {
            vis[index][cnt]=1;
            return dp[index][cnt]=nt;
        } 
        vis[index][cnt]=1;
        return dp[index][cnt]=t;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        vector<vector<int>> inter;
        for(int i=0;i<intervals.size();i++)
        {
            vector<int>tempo=intervals[i];
            tempo.push_back(i);
            inter.push_back(tempo);
        }
        vector<vector<Node>>dp(inter.size(),vector<Node>(5));
        vector<vector<int>>vis(inter.size(),vector<int>(5,-1));
        sort(inter.begin(),inter.end());
        vector<int>nex(inter.size(),-1);
        for(int i=0;i<inter.size();i++)
        {
            nex[i]=find(inter,inter[i][1],i);
        }
        Node result=solve(inter,nex,0,0,dp,vis);
        return result.ind;
    }
};