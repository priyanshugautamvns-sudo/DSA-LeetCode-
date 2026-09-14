class Solution {
public:
    bool dfs(vector<int>& vis,vector<int>& pvis,vector<int>adj[],int i)
    {
        if(vis[i]==1 && pvis[i]==1) return false;
        else if(vis[i]==1)
        {
            return true;
        }
        vis[i]=1;
        pvis[i]=1;
        for(int j=0;j<adj[i].size();j++)
        {
            if(dfs(vis,pvis,adj,adj[i][j])==false)
            {
                return false;
            }
        }
        pvis[i]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int>vis(numCourses,0);
        vector<int>pvis(numCourses,0);
        vector<int>adj[numCourses];
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(vis, pvis, adj, i) == false)
                    return false;
            }
        }
        return true;
    }
};