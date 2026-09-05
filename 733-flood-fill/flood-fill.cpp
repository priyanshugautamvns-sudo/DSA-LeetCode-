class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int wc=image[sr][sc];
        if(wc==color) return image;
        image[sr][sc]=color;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            if(r>0 && image[r-1][c]==wc)
            {
                image[r-1][c]=color;
                q.push({r-1,c});
            }
            if(r<n-1 && image[r+1][c]==wc)
            {
                image[r+1][c]=color;
                q.push({r+1,c});
            }
            if(c>0 && image[r][c-1]==wc)
            {
                image[r][c-1]=color;
                q.push({r,c-1});
            }
            if(c<m-1 && image[r][c+1]==wc)
            {
                image[r][c+1]=color;
                q.push({r,c+1});
            }
        }
        return image;
    }
};