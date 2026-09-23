class Solution {
public:
    int solve(string& s, int k, char target) {
        int l = 0;
        int changes = 0;
        int ans = 0;
        for (int r = 0; r < s.size(); r++) {
            if (s[r] != target) {
                changes++;
            }

            // if f > k
            while (changes > k) {
                if (s[l]!=target)
                    changes--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int makeT = solve(answerKey, k, 'T');
        int makeF = solve(answerKey, k, 'F');
        return max(makeT, makeF);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna