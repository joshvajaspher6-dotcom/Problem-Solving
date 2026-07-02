class disjoinsize
{
    public:
        vector<int> parent,size;

        disjoinsize(int n)
        {
            parent.resize(n);
            size.resize(n,1);
            for (int i=0;i<n;i++)
                parent[i]=i;

        }

        int findparent(int node)
        {
            if(node == parent[node])
                return node;

            return parent[node] = findparent(parent[node]);   
        }

        void join_node(int u,int v)
        {
            int up = findparent(u);
            int vp = findparent(v);

            if(up==vp)
                return;

            if(size[up]<size[vp])
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


    bool isValid(int x,int y,int n)
    {
        return  x >=0 && x < n && y >=0 && y <n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoinsize ds(n*n);

        vector<int> deltaRow={-1,0,1,0};
        vector<int> deltaCol = {0,1,0,-1};

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;

                for (int k =0;k<4;k++)
                {
                    int nx = i+ deltaRow[k];
                    int ny = j+ deltaCol[k];

                    if(isValid(nx,ny,n) && grid[nx][ny]==1)
                    {
                        int nr = i * n+j;
                        int adj_node = nx*n +ny;

                        ds.join_node(nr,adj_node); 
                    }
                }    
            }
        }


        int maxi=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    maxi = max(maxi,ds.size[ds.findparent(i*n+j)]);
            }
        }

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                set<int> st;
                int sum =1;
                if(grid[i][j]==1)
                    continue;

                for (int k =0;k<4;k++)
                {
                    int nx = i+ deltaRow[k];
                    int ny = j + deltaCol[k];

                    if(isValid(nx,ny,n)&& grid[nx][ny]==1)
                    {
                        st.insert(ds.findparent(nx*n+ny));
                    }
                } 
                for (auto it: st)
                {
                    sum+=ds.size[it];
                } 
                maxi = max(maxi,sum);

            }
        }
        return maxi;

    }
};