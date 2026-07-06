class Solution {
public:
    void solve(string& s, int i, vector<string>& currp, vector<vector<bool>>& t,
               vector<vector<string>>& result) {
        if (i == s.length()){
             result.push_back(currp);
            return ;
        }
        for( int j=i;j<s.length();j++){
            if(t[i][j]==true){
                currp.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currp, t, result);
                currp.pop_back();
            }
        }
           
    }


    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            t[i][i] = true;
        }
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i < n - l + 1; ++i) {
                int j = i + l - 1;
                if (s[i] == s[j]) {
                    if (l == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i + 1][j - 1];
                    }
                }
            }
        }
        vector<vector<string>> result;
        vector<string> currp;
        solve(s, 0, currp, t, result);
        return result;
    }
};