class Solution {
public:
int n;
//dfs logic 
void dfs( unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited){
    visited[u]=true;
    for(auto &v : adj[u]){
        if(!visited[v]){
            dfs(adj,v,visited);
            
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
         n = isConnected.size();
        
        //adj initalize krenge 
        unordered_map<int, vector<int>> adj;

        // matrix pe iterate krenge
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    
                }

            }
        }

        //main logic count 
        int count=0;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};