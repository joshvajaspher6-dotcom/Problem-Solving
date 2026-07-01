class DisJoinSize
{
    public:
        vector<int> parent,size;
        inline static int extra_edges=0;
        DisJoinSize(int n)
        {
            parent.resize(n);
            size.resize(n,1);
            for (int i=0;i<n;i++)
                parent[i]=i;
        }

        int findParent(int node)
        {
            if(node == parent[node])
                return node;

            return parent[node]=findParent(parent[node]);    
        }

        void joinComponent(int u,int v)
        {
            int up = findParent(u);
            int vp = findParent(v);

            if(up==vp)
            {
                extra_edges++;
                return;
            }

            else if(size[up]< size[vp])
            {
                parent[up]=vp;
                size[vp]+=size[up];
            }  
            else
            {
                parent[vp]=up;
                size[up]+=size[vp];
            }  

        }

};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJoinSize ds(n);

        for (auto it: connections)
        {
            ds.joinComponent(it[0],it[1]);
        }

        int connectedComponenets=0;

        for (int i=0;i<n;i++)
        {
            if(i==ds.findParent(i))
                connectedComponenets++;
        }
        int s = ds.extra_edges;
        ds.extra_edges=0;

        if(s >=connectedComponenets-1)
            return connectedComponenets-1;
        else
            return -1;    
    }
};