class DisJoinSize
{
    vector<int> size,parent;

    public:
        DisJoinSize(int n)
        {
            size.resize(n+1,1);
            parent.resize(n+1);

            for (int i=0;i<n;i++)
                parent[i]=i;
        }

        int findParent(int node)
        {
            if(node == parent[node])
                return node;

            return parent[node]=findParent(parent[node]);

        }

        void joinNode(int u,int v)
        {
            int up = findParent(u);
            int vp = findParent(v);

            if(up==vp)
                return;
            else if(size[up]<size[vp])
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJoinSize ds(n);

        unordered_map<string,int>mpp;

        for (int i=0;i<n;i++)
        {
            for (int j=1;j<accounts[i].size();j++)
            {
                if(mpp.find(accounts[i][j])==mpp.end())
                {
                    mpp[accounts[i][j]]=i;
                }
                else
                {
                    ds.joinNode(i,ds.findParent(mpp[accounts[i][j]]));
                }
            }
        }

        vector<string> mail[n];
        for (auto it: mpp)
        {
            string email = it.first;
            int node = ds.findParent(it.second);
            mail[node].push_back(email);
        }

        vector<vector<string>> res;
        for (int i=0;i<n;i++)
        {
             vector<string> temp;
            sort(mail[i].begin(),mail[i].end());
            if(mail[i].size()==0)
                continue;
            temp.push_back(accounts[i][0]);

            for (auto it:mail[i])
            {
                temp.push_back(it);
            } 
            res.push_back(temp);   
        }
        return res;
    }
};