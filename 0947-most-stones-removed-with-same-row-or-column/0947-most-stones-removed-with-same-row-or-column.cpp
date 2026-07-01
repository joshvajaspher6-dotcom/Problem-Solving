class disJoinSize
{
    public:
        vector<int> size,parent;

        disJoinSize(int n)
        {
            size.resize(n,1);
            parent.resize(n);
            for (int i=0;i<n;i++)
                parent[i]=i;
        }   

        int findParent(int node)
        {
            if(node==parent[node])
                return node;

            return parent[node]=findParent(parent[node]);    
        }

        void joinNode(int u,int v)
        {
            int up = findParent(u);
            int vp = findParent(v);

            if(up ==vp)
                return;

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
    int removeStones(vector<vector<int>>& stones) {
        int maxCol=0;
        int maxRow =0;
        int n = stones.size();
        for (auto it: stones)
        {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        disJoinSize ds(maxRow+maxCol+2);
        unordered_map<int,int> mpp;
       
        for (auto it:stones)
        {
            ds.joinNode(it[0],it[1]+maxRow+1);
            mpp[it[0]]=1;
            mpp[it[1]+maxRow+1]=1;
        }

        int cnt =0;
        for (auto it:mpp)
        {
            if(it.first==ds.findParent(it.first))
                cnt++;
        }
        return n-cnt;
    }
};