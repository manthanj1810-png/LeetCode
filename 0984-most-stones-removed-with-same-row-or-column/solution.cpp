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
    int removeStones(vector<vector<int>>& stones) {
       int s=stones.size();
       DisjointSet ds(s);
       for(int i=0;i<s;i++){
        for(int j=i;j<s;j++){
            if(i!=j){
                auto &it=stones[i];
                auto &jt=stones[j];
                int ui=it[0],uj=it[1],vi=jt[0],vj=jt[1];
                if(ui==vi || uj==vj){
                    ds.join(i,j);
                }
            }
        }
       }
       set<int> st;
       for(int i=0;i<s;i++){
        st.insert(ds.findup(i));
       }
       return s-st.size();
    }
};
