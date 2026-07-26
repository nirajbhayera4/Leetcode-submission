class Solution {
public:
vector<int> parent;
vector<int> rank;
int find(int i){
    if(parent[i]==i)return i;
    return parent[i]=find(parent[i]);
}
void Union(int x, int y){
    int xp=find(x);
    int yp=find(y);
    if(xp==yp)return;

    if(rank[xp]> rank[yp]){
        parent[yp]=xp;
    }
    else if(rank[xp]< rank[yp]){
        parent[xp]=yp;
    }
    else {
        parent[xp]=yp;
        rank[yp]++;
    }



}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)return -1;
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int comp=n;

        for(auto &v :connections){
            if(find(v[0])!=find(v[1])){
                Union(v[0], v[1]);
                comp--;
            }

        }
        return comp-1;
    }
};