class Solution {
public:

//bfs se krenge 
bool bipartite(vector<vector<int>>& graph, int u, vector<int>& color, int currcolor){
    queue<int> q;
    q.push(u);
    color[u]=currcolor;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto &vec : graph[curr]){
            if(color[vec]==color[curr])return false;
            if(color[vec]==-1){
               
                // bfs hai to wapis queue me push kr denge 
                color[vec] = 1 - color[curr];// wapis assign kr denge 
                q.push(vec);
            }
        }

    }
    return true;
}
/*
bool bipartite(vector<vector<int>>& graph, int u, vector<int> &color, int currcolor){
    color[u]=currcolor;
    for(auto &v : graph[u]){
        if(color[v]==color[u])return false;

        if(color[v]==-1){
            int colorv=1-currcolor;
            if(bipartite(graph,v,color, colorv)==false)return false;

        }
    }
    return true;
}
*/

    bool isBipartite(vector<vector<int>>& graph) {
         int n=graph.size();
        vector<int> color(n,-1);
       

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bipartite(graph,i,color,1)==false)return false;
            }
            
        }
        return true;
    }
};