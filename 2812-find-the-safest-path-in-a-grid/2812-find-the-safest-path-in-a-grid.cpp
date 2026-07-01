class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>board(n,vector<int>(m));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                    board[i][j]=0;
                }
            }
        }
        vector<int> deltaRow={-1,0,1,0};
        vector<int> deltaCol={0,1,0,-1};

        while(!q.empty())
        {
            auto el = q.front();
            q.pop();
            int step = el.first;
            int x = el.second.first;
            int y = el.second.second;
            board[x][y]=step;

            for (int i=0;i<4;i++)
            {
                int nx = x+deltaRow[i];
                int ny = y+deltaCol[i];

                if(nx >=0 && nx <n && ny >=0 && ny <m && vis[nx][ny]==0)
                {
                    vis[nx][ny]=1;
                    q.push({step+1,{nx,ny}});
                }
            }
        }

        if(board[0][0]==0 || board[n-1][m-1]==0)
            return 0;

        for (auto &a:vis)
            fill(a.begin(),a.end(),0);

        priority_queue<pair<int,pair<int,int>>> pq;

        pq.push({board[0][0],{0,0}});
        vis[0][0]=1;

        int mini=board[0][0];

        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            int value = el.first;
            int x = el.second.first;
            int y = el.second.second;
            
            mini= min(mini,value);
            if(x==n-1 && y ==m-1)
                return mini;

            for (int i=0;i<4;i++)
            {
                int nx = x+deltaRow[i];
                int ny = y+deltaCol[i];
                
                if(nx >=0 && nx<n && ny >=0 && ny <m && vis[nx][ny]==0)
                {
                    pq.push({board[nx][ny],{nx,ny}});
                    vis[nx][ny]=1;
                }
            }
        }

    return 1;
    }
};