class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int i){
    if(parent[i]==i){
        return i;
    }
    return parent[i]=find(parent[i]);
}
void Union(int x, int y){
    int x_parent=find(x);
    int y_parent=find(y);

    if(x_parent==y_parent){
        return ;
    }
    if(rank[x_parent] > rank[y_parent]){
        parent[y_parent]=x_parent;

    }
    else if(rank[x_parent]<rank[y_parent]){
        parent[x_parent]=y_parent;
    }

    else{
        parent[x_parent]=y_parent;
        rank[y_parent]++;
    }
    

}
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;

        }
        // equals wala case 
        for(string &s : equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        // "!" wala case 
        for(string &s : equations){
            if(s[1]=='!'){
                char first=s[0];
                char second=s[3];

                int f_p=find(first -'a');
                int s_p=find(second -'a');
                if(f_p ==s_p){
                    return false;
                }
            }
            
        }
        return true;
    }
};