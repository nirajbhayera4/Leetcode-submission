class Solution {
public:
/*
    int n;
    int t[1001][1001];

    int solve(vector<vector<int>>& pairs, int i, int P) {
        if (i >= n) {
            // out od bound check krenge
            return 0;
        }

        if (P != -1 && t[i][P] != -1) {
            return t[i][P];
        }
        int take = 0;

        if (P == -1 || pairs[P][1] < pairs[i][0]) {
            take = 1 + solve(pairs, i + 1, i);

            // warna skip krdo
        }
        int skip = solve(pairs, i + 1, P);
        if (P != -1) {
            t[i][P] = max(take, skip);
        }

        return max(take, skip);
    }
    */
    
    int findLongestChain(vector<vector<int>>& pairs) {
         int n = pairs.size();

        // initialize dp
        //memset(t, -1, sizeof(t));
        //sort(begin(pairs),end(pairs));
        //return solve(pairs, 0, -1);
        vector<int> t(n,1);
        sort(begin(pairs),end(pairs));
        
        int maxLIS=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<  pairs[i][0]){
                    t[i]=max(t[i],t[j]+1 );
                    maxLIS=max(maxLIS,t[i]);
                }
            }
            
        }
        return maxLIS;
        


    
    }
};