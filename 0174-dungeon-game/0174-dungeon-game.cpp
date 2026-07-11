class Solution {
public:
int m,n;
int t[202][202];
int solve(int i, int j, vector<vector<int>> &grid){
    if(i >=m || j>=n){
        return 1e9;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    if(i ==m-1 && j==n-1){
        if(grid[i][j]>0){
            return 1;
        }
        else{
            return abs(grid[i][j]) +1;
        }
    }
    int right=solve(i,j+1,grid);
    int down=solve(i+1,j,grid);
    int result=min(right, down) - grid[i][j];
    return t[i][j]=(result >0)? result: 1;
}
    int calculateMinimumHP(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,grid);
    }
};