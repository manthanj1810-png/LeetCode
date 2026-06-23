class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findup(int u){
        if(u==parent[u]) return u;
        return parent[u]=findup(parent[u]);
    }
    void join(int u,int v){
        int up_u=findup(u), up_v=findup(v);
        if(up_u==up_v){
            return;
        }
        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else{
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       int s=accounts.size();
       DisjointSet ds(s);
       unordered_map<string, int> mp;
       for(int i=0;i<s;i++){
        for(int j=1;j<accounts[i].size();j++){
            string mail=accounts[i][j];
            if(mp.find(mail)!=mp.end()){
                ds.join(i,mp[mail]);
            }
            else{
                mp[mail]=i;
            }
        }
       }
       vector<string> merge[s];
       for(auto it:mp){
        int node=ds.findup(it.second);
        string mail=it.first;
        merge[node].push_back(mail);
       }
       vector<vector<string>> ans;
       for(int i=0;i<s;i++){
        if(merge[i].size()==0) continue;
        sort(merge[i].begin(),merge[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(int j=0;j<merge[i].size();j++){
            temp.push_back(merge[i][j]);
        }
        ans.push_back(temp);
       }
    return ans;
    }
};
