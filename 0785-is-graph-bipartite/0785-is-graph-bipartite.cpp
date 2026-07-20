class Solution {
public:
bool checkB(vector<vector<int>>& adj,int curr, vector<int>& color, int curcolor){
    color[curr]=curcolor;
    for(int &v : adj[curr]){
        if(color[v]==color[curr])return false;

        if(color[v]==-1){
            int colorV=1-curcolor;

            if(checkB(adj, v,color,colorV )==false)return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();

        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(checkB(adj,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;

    }
};