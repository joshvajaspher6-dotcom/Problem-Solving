class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[sr][sc];
       
        if (originalColor == color) {
            return image;
        }
        queue<pair<int,int>> q;
        vector<vector<bool>>vis(n+1,vector<bool>(m+1,false));
        q.push({sr,sc});
        vis[sr][sc]= true;
        image[sr][sc]= color;

        while(!q.empty())
        {
            auto[x,y] = q.front();
            q.pop();

            if(x+1<n && y<m && vis[x+1][y]==false && image[x+1][y] == originalColor)
            {
                image[x+1][y]= color;
                vis[x+1][y]=true;
                q.push({x+1,y});
            }
            if(x<n && y+1<m && vis[x][y+1]==false && image[x][y+1] == originalColor)
            {
                image[x][y+1]= color;
                vis[x][y+1]=true;
                q.push({x,y+1});
            }
            if(x<n && y-1>=0 && vis[x][y-1]==false && image[x][y-1] == originalColor)
            {
                image[x][y-1]= color;
                vis[x][y-1]=true;
                q.push({x,y-1});
            }
            if(x-1>=0 && y<m && vis[x-1][y]==false && image[x-1][y] == originalColor)
            {
                image[x-1][y] = color;
                vis[x-1][y]=true;
                q.push({x-1,y});
            }
        }
        return image;
    }
};