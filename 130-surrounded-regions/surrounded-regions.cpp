class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && (i==0 || j==0 || i==n-1 || j==m-1)) 
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x1=x+dx[i];
                int y1=y+dy[i];
                if((x1>=0 && y1>=0) && (x1<n && y1<m))
                {
                    if(board[x][y]=='O' && vis[x1][y1]==0)
                    {
                        vis[x1][y1]=1;
                        q.push({x1,y1});
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && board[i][j]=='O') 
                {
                    board[i][j]='X';
                }
            }
        }
    }
};