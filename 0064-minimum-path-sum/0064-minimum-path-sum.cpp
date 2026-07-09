class Solution {
public:
int t[202][202];
int solve(int i,int j, int m, int n,vector<vector<int>>& grid)
{
    if(i==m-1 && j==n-1){
        return grid[i][j];
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    if(i >=m || j>=n){
        return INT_MAX;
    }
    int right=  solve(i+1,j,m,n,grid);
    int down=  solve(i,j+1,m,n,grid);
    int sum=min(right, down);
    
    if(sum ==INT_MAX){
        return INT_MAX;

    }
    return t[i][j]=grid[i][j] + sum;

}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n,grid);
    }
};