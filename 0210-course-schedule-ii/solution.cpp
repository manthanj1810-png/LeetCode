class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans,empt;

        // build graph and indegree
        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            graph[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        // push all nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int completed = 0;

        // BFS
        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            completed++;

            for (int nei : graph[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        return completed==numCourses? ans : empt;
    }
};
