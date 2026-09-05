class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        int cnt=0;
        while(!q.empty())
        {
            bool flag=false;
            int s=q.size();
            while(s--)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(r>0 && grid[r-1][c]==1) 
                {
                    if(vis[r-1][c]==0)
                    {
                        q.push({r-1,c});
                        vis[r-1][c]=2;
                        flag=true;
                        fresh--;
                    }
                }
                if(r<n-1 && grid[r+1][c]==1) 
                {
                    if(vis[r+1][c]==0)
                    {
                        q.push({r+1,c});
                        vis[r+1][c]=2;
                        flag=true;
                        fresh--;
                    }
                }
                if(c>0 && grid[r][c-1]==1) 
                {
                    if(vis[r][c-1]==0)
                    {
                        q.push({r,c-1});
                        vis[r][c-1]=2;
                        flag=true;
                        fresh--;
                    }
                }
                if(c<m-1 && grid[r][c+1]==1) 
                {
                    if(vis[r][c+1]==0)
                    {
                        q.push({r,c+1});
                        vis[r][c+1]=2;
                        flag=true;
                        fresh--;
                    }
                }
            }          
            if(flag) cnt++;  
        }
        if(fresh!=0) return -1;
        return cnt;
    }
};