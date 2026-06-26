class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int l = flights.size();
        int m = flights[0].size();

        vector<vector<pair<int,int>>> adj(n);
        
            for (auto it : flights)
            {
                adj[it[0]].push_back({it[1],it[2]});
            }
        
        vector<int> dist(n,1e9);
        

        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;

        q.push({0,{src,0}});


        while(!q.empty())
        {
            auto it = q.front();
            int w = it.first;
            int node = it.second.first;
            int weight = it.second.second;
            q.pop();

            if(w > k)
                continue;

            for (auto it : adj[node])
            {
                int i = it.first;
                int edgeWeight= it.second;
                if(weight+edgeWeight <dist[i] && w<=k)
                {
                    dist[i]=weight+edgeWeight;
                    q.push({w+1,{i,weight+edgeWeight}});
                }
            }
        }
        if(dist[dst]!=1e9)
        {
            return dist[dst];
        }
        else
            return -1;

    }
};