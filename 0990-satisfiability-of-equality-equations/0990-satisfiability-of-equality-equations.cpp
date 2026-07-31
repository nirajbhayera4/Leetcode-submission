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
            parent[yp]=xp;
        }
        else if(rank[xp]<rank[yp]){
            parent[xp]=yp;
        }
        else{
            parent[xp]=yp;
            rank[yp]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (string& s : equations) {
            if (s[1] == '=') {
                Union(s[0] - 'a', s[3] - 'a');
            }
        }

        for(string &s: equations){
            if(s[1]=='!'){
                char first=s[0]; //a
                char second=s[3];//b

                int fp=find(first- 'a');
                int sp=find(second- 'a');


                if(fp==sp)return false;

            }
        }
        return true;
    }
};