class Solution {

private:
    bool dfs(int i,vector<vector<int>>& graph,int col,vector<int>& vis)
    {
        vis[i]=col;

        for (auto it: graph[i])
        {
            if(vis[it]==-1)
            {
                if(dfs(it,graph,!col,vis)==false)
                    return false;
                
            }
            else if(vis[it]==col)
                return false;    
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n+1,-1);

        for (int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                if(dfs(i,graph,0,vis)==false)
                    return false;
            }
        }
        return true;
    }
};