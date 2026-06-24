class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>>vis(n,vector<int>(m,false));

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        
                    }
                }
            }
        }
        vector<int> delCol = {-1,0,1,0};
        vector<int> delRow = {0,1,0,-1};

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            vis[x][y]=true;

            for (int i=0;i<4;i++)
            {
                int row = delRow[i]+x;
                int col = delCol[i]+y;

                if(row >=0 && col >=0 && row<n && col <m && grid[row][col]==1 &&
                                                                 vis[row][col]==false)
                {
                    q.push({row,col});
                    vis[row][col]=true;
                }
            }

        }
        int cnt =0;

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(vis[i][j]==false && grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};