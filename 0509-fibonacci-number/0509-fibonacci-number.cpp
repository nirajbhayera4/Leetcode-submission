
class Solution {
public:
    /*Solution()
    {
        memset(dp,-1,sizeof(dp));
    }
    */

    /*int solve(int n, vector<int>& t) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (t[n] != -1)
            return t[n];
        return t[n] = fib(n - 1) + fib(n - 2);
    }
    */
    int fib(int n) {
        int t[31];
        memset(t, -1, sizeof(t));
        function<int(int)> solve = [&](int n) {
            if (n == 0)
                return 0;
            if (n == 1)
                return 1;
            if (t[n] != -1)
                return t[n];
            return t[n] = solve(n - 1) + solve(n - 2);
        }; return solve(n);
    }
};