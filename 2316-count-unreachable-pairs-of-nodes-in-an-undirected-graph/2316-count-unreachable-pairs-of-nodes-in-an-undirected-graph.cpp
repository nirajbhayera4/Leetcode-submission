class Solution {
public:
vector<int> parent;
vector<int>rank;
int find(int i){
    if(parent[i]==i)return i;

    return parent[i]=find(parent[i]);
}
void Union(int x, int y){
    int xp=find(x);
    int yp=find(y);
    if(xp==yp)return;
    if(rank[xp]> rank[yp]){
        parent[xp]=yp;
    }
    else if(rank[xp]< rank[yp]){
        parent[yp]=xp;
    }
    else{
        parent[xp]=yp;
        rank[yp]++;
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &vec :edges){
            int u=vec[0];
            int v=vec[1];
            Union(vec[0], vec[1]);

        }
        // map bana lenge and iterate kr denge 
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            int parent=find(i);
            mp[parent]++;
        }

        // result nikal lenge
        long long res=0;
        long long rem=n;
        for(auto &it : mp){
            long long size=it.second;
            res+=(size) * (rem -size);
            rem-=size;
        }
        return res;
    }
};