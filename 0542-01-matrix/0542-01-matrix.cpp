class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        for (int i=0;i<n;i++)
        {
            for (int j =0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[row][col]=step;

            for (int i=0;i<4;i++)
            {
                int drow = row+dr[i];
                int dcol = col+dc[i];

                if(drow<n && drow>=0 && dcol<m && dcol>=0 && vis[drow][dcol]==false)
                {
                    q.push({{drow,dcol},step+1});
                    vis[drow][dcol]=true;
                }
            }
            
        }

        return dist;
    }
};