class Solution {
public:
int M=1e9 +7;
int dp[1001][1001];
/*
//------------RECURSIVE-----------
int solve(int n , int k , int i){
    if(k==0){
        return 1;
    }
    if(i >=n )return 0;
    if(t[k][i]!=-1){
        return t[k][i];
    }

    long long  take=0;
    for(int j=i+1;j<=n-1;j++){
        take=(take + solve(n,k-1,j)) %M;
    }
    long long  skip=solve(n,k,i+1) %M;
    return t[k][i]=skip + take;
}
*/
//---------BOTTOM  UPP------------
    int numberOfSets(int n, int K) {
        //memset(t,-1,sizeof(t));
        //return solve(n,k,0) % M;
        for(int i=0;i<=n;i++){
            dp[0][i]=1;
        }

        for(int k=1;k<=K;k++){
            vector<int> prevrowsum(n+1,0);
            for(int x=n-1;x>=0;x--){
                prevrowsum[x]=(prevrowsum[x+1] + dp[k-1][x])%M;
            }
            for(int i=n-1;i>=0;i--){
                int take=prevrowsum[i+1];
                int skip=dp[k][i+1];
                dp[k][i]=(take + skip) %M;
            }
        }
        return dp[K][0];

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna