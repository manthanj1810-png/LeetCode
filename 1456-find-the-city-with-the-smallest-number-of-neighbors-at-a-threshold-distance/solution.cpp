class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        int minReach = INT_MAX;
        int city = -1;
        
        for(int i = 0; i < n; i++) {
            
            vector<int> dis(n, INT_MAX);
            
            priority_queue<
                pair<int,int>, 
                vector<pair<int,int>>, 
                greater<pair<int,int>>
            > pq;
            
            dis[i] = 0;
            pq.push({0, i});
            
            while(!pq.empty()) {
                auto [d,u] = pq.top();
                pq.pop();
                
                if(d > dis[u]) continue;   // VERY IMPORTANT
                
                for(auto &it : adj[u]) {
                    int v = it.first;
                    int wt = it.second;
                    
                    if(dis[u] + wt < dis[v]) {
                        dis[v] = dis[u] + wt;
                        pq.push({dis[v], v});
                    }
                }
            }
            
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dis[j] <= t)
                    count++;
            }
            
            // tie -> choose larger index
            if(count <= minReach) {
                minReach = count;
                city = i;
            }
        }
        
        return city;
    }
};
