class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0;
        int minsum=0;
        for(int x : nums){
            sum+=x;
            minsum=min(minsum,sum);
        }
        return 1-minsum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna