class Solution {
public:
    int climbStairs(int n) {
        
        /*if(n==1)return 1;
        if(n==2)return 2;
        vector<int> t(n+1);
        
        t[1]=1;
        t[2]=2;
        for(int i=3;i<=n;i++){
            t[i]=t[i-1] + t[i-2];

        }
        return t[n];
        */
        if(n==1)return 1;
        if(n==2)return 2;

        int a=1;
        int b=2;
        
        for(int i=3;i<=n;i++){
            int c=b+a;
            a=b;
            b=c;
        }
        return b;
    }
};