class DisjoinSize
{
    public:
    vector<int> size,parent;

        DisjoinSize(int n)
        {
            size.resize(n+1,1);
            parent.resize(n+1);
            for (int i=0;i<=n;i++)
                parent[i]=i;

        }

        int findParent(int node)
        {
            if(node==parent[node])
            {
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }

        void joinComponenets(int u,int v)
        {
            int rootParentU = findParent(u);
            int rootParentV = findParent(v);
            if(rootParentU == rootParentV)
                return;

            if(size[rootParentU]<size[rootParentV])
            {
                parent[rootParentU]= rootParentV;
                size[rootParentV] += size[rootParentU];
            }
            else
            {
                parent[rootParentV]= rootParentU;
                size[rootParentU] += size[rootParentV];
            }

        }
};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjoinSize ds(n);

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                    ds.joinComponenets(i,j);
            }
        }

        int cnt = 0;

        for (int i=0;i<n;i++)
        {
            if(i==ds.findParent(i))
                cnt++;
        }
        return cnt;
    }
};