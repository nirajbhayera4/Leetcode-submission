class Solution {
public:
int t[501][501];


int solve(string &w1, string &w2, int i, int  j){
    if(t[i][j] !=-1){
        return t[i][j];
    }
   if(i ==w1.size())return w2.size() -j;

   if(j==w2.size())return w1.size() -i;

   if(w1[i] ==w2[j]){
    return t[i][j]=solve(w1, w2, i+1, j+1);
   }
   int replace=1 + solve(w1, w2, i+1, j+1);
   int insert=1 + solve(w1, w2, i, j+1);
   int del= 1 + solve(w1,w2, i+1, j);

   return t[i][j]=min({replace, insert, del});

}
    int minDistance(string w1, string w2) {
        memset(t,-1,sizeof(t));
        return solve(w1, w2,0,0);
    }
};