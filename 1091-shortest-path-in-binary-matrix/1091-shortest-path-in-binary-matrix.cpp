class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        // dijkstra's using queue;
        if(grid[0][0]==1 || grid[n-1][m-1]==1)
            return -1;

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});

        vector<int> deltaRow = {-1,-1,-1,0,0,1,1,1};
        vector<int> deltaCol = {-1,0,1,-1,1,-1,0,1};

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        dist[0][0]=1;

        while(!q.empty())
        {
            auto it =q.front();
            q.pop();

            int weight = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(x==n-1 && y==m-1)
            {
                return weight;
            }

            for (int i=0;i<8;i++)
            {
                int row = x+deltaRow[i];
                int col = y+deltaCol[i];

                if(row >=0 && col >=0 && row <n && col < m && grid[row][col]==0)
                {
                    if(dist[row][col]> weight+1)
                    {
                        dist[row][col]= weight+1;
                        q.push({weight+1,{row,col}});
                    }
                }
            }
        }
        return -1;

    }
};