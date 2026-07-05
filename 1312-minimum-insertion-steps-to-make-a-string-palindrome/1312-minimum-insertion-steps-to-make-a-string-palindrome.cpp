class Solution {
public:
    vector<vector<int>> t;

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

    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();
        t.assign(n, vector<int>(n, -1));

        int lps = solve(s, rev, 0, 0);

        return n - lps;
    }
};