class Solution {
public:
/*int m,n;
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
*/

    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //memset(t,-1,sizeof(t));
        //return solve(0,0,grid);

        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    if(grid[i][j] >0){
                        t[i][j]=1;
                    }
                    else{
                        t[i][j]=abs(grid[i][j]) +1;
                    }
                }
                else{
                    int right= (j+1>=n) ? 1e9 : t[i][j+1];
                    int down=(i+1 >=m) ? 1e9 : t[i+1][j];

                    int result=min(right, down) - grid[i][j];
                    t[i][j]=result >0? result :1;

                }
            }
        }
        return t[0][0];
    }
};