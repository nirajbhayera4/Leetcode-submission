class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;

        int sum = 0;

        if (k > 0) {

            // Initial window: next k elements of index 0
            for (int j = 1; j <= k; j++) {
                sum += code[j % n];
            }

            for (int i = 0; i < n; i++) {

                ans[i] = sum;

                // Remove element leaving the window
                sum -= code[(i + 1) % n];

                // Add new element entering the window
                sum += code[(i + k + 1) % n];
            }

        } else {

            k = -k;

            // Initial window: previous k elements of index 0
            for (int j = 1; j <= k; j++) {
                sum += code[(n - j) % n];
            }

            for (int i = 0; i < n; i++) {

                ans[i] = sum;

                // Remove the oldest previous element
                sum -= code[(i - k + n) % n];

                // Add the new previous element
                sum += code[i % n];
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna