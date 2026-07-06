class Solution {
public:
    /*vector<vector<int>> t;

    int solve(string &s, string &rev, int i, int j) {
        if (i == s.size() || j == rev.size())
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        if (s[i] == rev[j])
            return t[i][j] = 1 + solve(s, rev, i + 1, j + 1);

        return t[i][j] = max(
            solve(s, rev, i + 1, j),
            solve(s, rev, i, j + 1)
        );
    }
    */

    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        vector<vector<int>> t(n+1, vector<int>(n+1,0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == rev[j-1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        // int lps = solve(s, rev, 0, 0);

        // return n - lps;
        return n - t[n][n];
    }
};