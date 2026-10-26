class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                long long sum=0;
                queue<pair<int,int>>q;
                if(grid[i][j]!=0)
                {
                    sum+=grid[i][j];
                    q.push({i,j});
                    grid[i][j]=0;
                }
                while(!q.empty())
                {
                    int fx=q.front().first;
                    int fy=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int x=fx+dx[k];
                        int y=fy+dy[k];
                        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!=0)
                        {
                            sum+=grid[x][y];
                            q.push({x,y});
                            grid[x][y]=0;
                        }
                    }
                }
                if(sum>0 && sum%k==0) cnt++;
            }
        }
        return cnt;
    }
};