class Solution {
public:
    bool helper(int u, vector<vector<int>>& lst,
                vector<bool>& vis, vector<bool>& pvis) {
        vis[u] = true;
        pvis[u] = true;

        for (int v : lst[u]) {
            if (!vis[v]) {
                if (helper(v, lst, vis, pvis)) return true;
            }
            else if (pvis[v]) {
                return true; // cycle found
            }
        }

        pvis[u] = false;  // 🔥 important fix
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int>> lst(n);
        for (auto &e : arr) {
            lst[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false), pvis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (helper(i, lst, vis, pvis))
                    return false;
            }
        }
        return true;
    }
};

