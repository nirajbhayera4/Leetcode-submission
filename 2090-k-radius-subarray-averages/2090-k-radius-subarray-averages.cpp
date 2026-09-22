class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> ans(n, -1);

        int windowSize = 2 * k + 1;

        // If the whole window cannot fit
        if(windowSize > n) {
            return ans;
        }

        long long sum = 0;

        // First window
        for(int i = 0; i < windowSize; i++) {
            sum += nums[i];
        }

        // Center of first window
        ans[k] = sum / windowSize;

        // Slide the window
        for(int i = windowSize; i < n; i++) {

            // Remove left element
            sum -= nums[i - windowSize];

            // Add new right element
            sum += nums[i];

            // Center of current window
            int center = i - k;

            ans[center] = sum / windowSize;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna