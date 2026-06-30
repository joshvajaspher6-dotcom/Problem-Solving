class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        for (auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v]=wt;
            dist[v][u]=wt;
        }
        for (int i=0;i<n;i++)
            dist[i][i]=0;

        for (int val =0;val<n;val++)
        {
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                {
                    if(dist[i][val]!=1e8 && dist[val][j]!=1e8)
                    {
                        dist[i][j] = min(dist[i][j],dist[i][val]+dist[val][j]);
                    }
                }
            }
        }
        vector<int> distCount(n,0);

        for (int i=0;i<n;i++)
        {
            int cnt =0;
            for (int j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold)
                {
                    cnt++;
                }
            }
            distCount[i]=cnt;
        }
        int mini =*min_element(distCount.begin(),distCount.end());

        int final_idx=0;
        for (int i=0;i<n;i++)
        {
            if(distCount[i]==mini)
            {
                final_idx=i;
            }
        }
        return final_idx;
    }
};