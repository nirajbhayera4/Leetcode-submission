class Solution {
public:
    int n;

    int maxPalindromes(string s, int k) {
        n = s.length();

        // palindrome[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of non-overlapping
        // palindromes we can get from index i onward
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Don't take a palindrome starting at i
            dp[i] = dp[i + 1];

            // Try every ending position
            for (int j = i + k - 1; j < n; j++) {

                if (palindrome[i][j]) {
                    dp[i] = max(dp[i],
                                1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna