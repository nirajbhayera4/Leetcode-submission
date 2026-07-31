class Solution {
public:
    bool tpsort(unordered_map<int, vector<int>> adj, int n,
                vector<int>& indegree) {
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                cnt++;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    cnt++;
                    q.push(v);
                }
            }
        }
        if (cnt == n) 
            return true; // mtlb cycle hai
        
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto& v : prerequisites) {
            int a = v[0];
            int b = v[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        return tpsort(adj, numCourses, indegree);
    }
};