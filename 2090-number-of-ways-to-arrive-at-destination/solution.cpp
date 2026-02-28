class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        
        priority_queue<
            pair<long long,int>, 
            vector<pair<long long,int>>, 
            greater<pair<long long,int>>
        > pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        
        while(!pq.empty()) {
            auto [d,u] = pq.top();
            pq.pop();
            
            if(d > dist[u]) continue;
            
            for(auto &it : adj[u]) {
                int v = it.first;
                long long wt = it.second;
                
                if(dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dist[u] + wt == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[n-1];
    }
};
