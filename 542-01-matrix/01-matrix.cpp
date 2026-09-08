class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            if(mat[x][y]==0) ans[x][y]=0;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0)
                {
                    ans[nx][ny]=1+ans[x][y];

                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
};