class Solution {
public:
int n;
//dfs logic 
void bfs( unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited){
    queue<int> q;
    q.push(u);
    visited[u]=true;

    //bfs lgayenge
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto &v : adj[curr]){
            if(!visited[v]){
                bfs(adj, v, visited);
            }
        }
    }
    /*
    for(auto &v : adj[u]){
        if(!visited[v]){
            dfs(adj,v,visited);
            
        }
    }
    */
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
                bfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};