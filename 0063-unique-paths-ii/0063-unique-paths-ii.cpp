class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        
        t[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;

       
        for(int i = 1; i < m; i++){
            if(obstacleGrid[i][0] == 1)
                t[i][0] = 0;
            else
                t[i][0] = t[i-1][0];
        }

       
        for(int j = 1; j < n; j++){
            if(obstacleGrid[0][j] == 1)
                t[0][j] = 0;
            else
                t[0][j] = t[0][j-1];
        }

       
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1)
                    t[i][j] = 0;
                else
                    t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];
    }
};