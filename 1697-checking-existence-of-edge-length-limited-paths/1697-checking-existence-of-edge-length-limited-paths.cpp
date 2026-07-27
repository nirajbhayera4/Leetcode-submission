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
    if(xp==yp)return ;
    if(rank[xp] > rank[yp]){
        parent[xp]=yp;
    }
    else if(rank[xp] < rank[yp]){
        parent[yp]=xp;
    }
    else{
        parent[xp]=yp;
        rank[yp]++;
    }

}


    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n);
        // starting me sb apne  apne parent hoge
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < queries.size(); i++) {
            // index mark kr denge
            queries[i].push_back(i);
        }
        // lambda use krenge taaki ascending order me sort kr ske
        auto lambda =
            [&](vector<int>& v1, vector<int>& v2) {
                return v1[2] < v2[2]; // edgelist me distance ke basis pe aur
                                      // queries me limit ke basis me ascending
                                      // order me sort kr lenge
            };
        // sort kr lenge taaki baar baar graph na banana pde
        sort(begin(edgeList), end(edgeList), lambda);
        sort(begin(queries), end(queries), lambda);

        vector<bool> result(queries.size());
        int j = 0;
        // queries ke components me traverse kr lenge
        for (int i = 0; i < queries.size(); i++) {
            vector<int> query = queries[i];
            int u = query[0];
            int v = query[1];
            int t = query[2];
            int idx = query[3];

            while(j <  edgeList.size() && edgeList[j][2] <t){
                Union(edgeList[j][0], edgeList[j][1]);
                j++;

            }
            //DSU
            if(find(u)==find(v)){
                result[idx]=true;
            }
            else{
                result[idx]=false;
            }

        }
        return result;
    }

};