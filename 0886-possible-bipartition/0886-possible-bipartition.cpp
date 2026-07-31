class Solution {
public:
bool checkDfs(vector<vector<int>>&adj, int u, vector<int> &color, int currcolor){
    color[u]=currcolor;
    for(auto &v : adj[u]){
        if(color[v]==color[u])return false;
        if(color[v]==-1){
            int colorv=1-currcolor;
            if(checkDfs(adj,v,color, colorv)==false)return false;
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
// adjencency list banani pdegi kyuki isme graph input me de rkha hai to hume khud banan pdegi 
        for(auto &v : dislikes){
            
            int a=v[0];
            int b=v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            


        }

        vector<int> color(n+1,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(checkDfs(adj,i, color, 1)==false)return false;
            }
        }
        return true;
    }
};