class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int i,int j,int n,int m)
    {
        vis[i][j]=1;
        if(i-1>=0 && board[i-1][j]=='O' && vis[i-1][j]==0) dfs(board,vis,i-1,j,n,m);
        if(i+1<=n-1 && board[i+1][j]=='O' && vis[i+1][j]==0) dfs(board,vis,i+1,j,n,m);
        if(j+1<=m-1 && board[i][j+1]=='O' && vis[i][j+1]==0) dfs(board,vis,i,j+1,n,m);
        if(j-1>=0 && board[i][j-1]=='O' && vis[i][j-1]==0) dfs(board,vis,i,j-1,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1))
                {
                    if(vis[i][j]==0)
                    {
                        dfs(board,vis,i,j,n,m);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && vis[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};