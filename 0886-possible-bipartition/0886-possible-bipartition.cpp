class Solution {
public:
bool checkB(vector<vector<int>>& adj, int node, vector<int>&color, int curcolor){
    color[node]=curcolor;
    for(int &v : adj[node]){
        if(color[v]==color[node])return false;
        if(color[v]==-1){
            int colorV=1-curcolor;
            if(!checkB(adj, v, color, colorV))return false;
        }
    }
    return true;

}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        // adjecency list banni padegi 
        for(auto &v : dislikes){
            int a=v[0];
            int b=v[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!checkB(adj, i, color, 1))return false;
            }
        }
        return true;
    }
};