class Solution {
public:
    vector<int> solve(string s) {
        vector<int> result;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left_res = solve(s.substr(0, i));
                vector<int> right_res = solve(s.substr(i + 1));

                for (int& x : left_res) {
                    for (int& y : right_res) {
                        if (s[i] == '+') {
                            result.push_back(x + y);
                        } else if (s[i] == '-') {
                            result.push_back(x - y);
                        } else {
                            result.push_back(x * y);
                        }
                    }
                }
            }
        }
        if(result.empty()){
            result.push_back(stoi(s));
        }
        return result;
    }
    vector<int> diffWaysToCompute(string s) { return solve(s); }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna