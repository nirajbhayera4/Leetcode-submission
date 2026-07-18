class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>>& adj,
                         int n,
                         vector<int>& indegree) {

        queue<int> q;
        vector<int> order;

        
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            order.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

      
        if (order.size() != n)
            return {};

        return order;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto& v : prerequisites) {
            int a = v[0];
            int b = v[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoSort(adj, numCourses, indegree);
    }
};