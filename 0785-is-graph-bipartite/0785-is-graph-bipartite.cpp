class Solution {
public:
bool checkB(vector<vector<int>>& graph, int node, vector<int> &color, int curcolor){
    color[node]=curcolor;
    for(int &v : graph[node]){
        if(color[v]==color[node])return false;
        if(color[v]==-1){
            int colorV=1-curcolor;
            if(!checkB(graph,v,color,colorV))return false;
        }
    }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!checkB(graph,i,color,1))return false;
            }
        }
        return true;
    }
};