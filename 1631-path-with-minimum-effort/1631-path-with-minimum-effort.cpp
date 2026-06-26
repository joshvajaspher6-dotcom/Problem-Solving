class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});

        int mini=INT_MAX;

        vector<int> deltaRow={-1,0,1,0};
        vector<int> deltaCol={0,1,0,-1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int weight = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x==n-1 && y==m-1)
            {
                mini= min(mini,weight);
            }

            for (int i=0;i<4;i++)
            {
                int nx = x+ deltaRow[i];
                int ny = y+ deltaCol[i];

                if(nx >=0 && ny >=0 && nx <n && ny <m)
                                
                {
                    int newEffort = max(abs(heights[x][y]-heights[nx][ny]),weight);
                    if(newEffort < dist[nx][ny])
                    {
                        dist[nx][ny]=newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }


        }
        return mini;
    }
};