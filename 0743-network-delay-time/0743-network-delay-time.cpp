class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int row = times.size();
        int col = times[0].size();

        vector<vector<pair<int,int>>> adj(n+1);

       
        for (auto it : times)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        

        vector<int> dist(n+1,1e9);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        dist[k]=0;
        pq.push({k,0});

        while(!pq.empty())
        {
            auto it= pq.top();
            int node = it.first;
            int weight = it.second;
            pq.pop();

            for (auto it : adj[node])
            {
                int el = it.first;
                int edgeWeight = it.second;
                if(weight+edgeWeight < dist[el])
                {
                    dist[el]= weight+edgeWeight;

                    pq.push({el,weight+edgeWeight});
                }
            }
        }
        int res= *max_element(dist.begin()+1,dist.end());
        if(res==1e9)
            return -1;
        return res;    
    }
};