class Solution {

private:
    void bfs(vector<vector<bool>>& vis,int i,int j,int n,int m,vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        vis[i][j]= true;
        q.push({i,j});

        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,1,0,-1};

        while(!q.empty())
        {
            auto[x,y]= q.front();
            q.pop();

            for (int i=0;i<4;i++)
            {
                int row = x + delRow[i];
                int col = y + delCol[i];

                if(row >=0 && col >=0 && row <n && col <m && vis[row][col]==false && 
                                    grid[row][col]=='1')
                {
                    vis[row][col]=true;
                    q.push({row,col});
                }                    

            }
        }
    }



public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int cnt =0;

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==false)
                {
                    cnt++;
                    bfs(vis,i,j,n,m,grid);
                }
            }
        }
        return cnt;
    }
};