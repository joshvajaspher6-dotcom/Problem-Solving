class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> max_health(n,vector<int>(m,-1));

        if(grid[0][0]==1)
            health-=1;

        pq.push({health,{0,0}});

        vector<int> deltaRow = {-1,0,1,0};
        vector<int> deltaCol = {0,1,0,-1};


        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int curr_health = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(curr_health <max_health[x][y])
                continue;

            if(x == n-1 && y == m-1)
                return true;

            for (int i=0;i<4;i++)
            {
                int nx = x+deltaRow[i];
                int ny = y+deltaCol[i];

                if(nx >=0 && nx<n && ny >=0 && ny <m)
                {
                    int next_health = curr_health-grid[nx][ny];

                    if(next_health >=1 && next_health > max_health[nx][ny])
                    {
                        pq.push({next_health,{nx,ny}});
                        max_health[nx][ny]=next_health;
                    }    
                      
                }    

            }
        }   
        return false; 
    }
};