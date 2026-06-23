class Solution {

private:
    void bfs(vector<vector<bool>>& vis,int i,int j,int n,int m,vector<vector<char>>& board)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;

        vector<int> deltaRow = {-1,0,1,0};
        vector<int> deltaCol = {0,1,0,-1};

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i=0;i<4;i++)
            {
                int row = x+deltaRow[i];
                int col = y+deltaCol[i];
                
                if(row<n && col <m && row >=0 && col >=0  && vis[row][col]==false 
                                                                && board[row][col]=='O')
                {
                    q.push({row,col});
                    vis[row][col]=true;
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for (int i =0;i<n;i++)
        {
            for (int j =0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(board[i][j]=='O')
                    {
                        bfs(vis,i,j,n,m,board);
                    }
                }
            }
        }

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && vis[i][j]==false)
                    board[i][j]='X';
            }
        }
    }
};