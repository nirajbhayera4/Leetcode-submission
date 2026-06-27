class Solution {
public:
int N,M,K;
int MOD=1e9 +7;
int t[51][51][102];

int solve(int idx, int search_cost , int max){
    if(idx==N){
        if(search_cost==K){
            return 1;
        }
        return 0;
    }
    if(t[idx][search_cost][max]!=-1){
        return t[idx][search_cost][max];
    }

    int res=0;
    for(int i=1;i <=M;i++){
        if(i >max){
            res= (res +solve(idx +1 , search_cost +1, i)) % MOD;
        }
        else {
            res= (res +solve(idx +1, search_cost , max)) %MOD;
        }

    }
    return t[idx][search_cost][max]=res % MOD;
}
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t, -1, sizeof(t));

        return solve(0,0,0);
    }
};