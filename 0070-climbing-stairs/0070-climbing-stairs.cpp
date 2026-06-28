class Solution {
public:
    int climbStairs(int n) {
        
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
        

        /*if(n==1 || n==2 || n==3){
            return n;
        }

        vector<int> t(n+1);

        t[0]=0;
        t[1]=1;
        t[2]=2;
        for(int i=3;i<=n;i++){
            t[i]=t[i-1] +t[i-2];
        }
        return t[n];
        */
    }
};