class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr=nums[0]; //-2
        int ans=nums[0]; //-2 

        for(int i=1;i<n;i++){
            curr=max(nums[i] ,curr + nums[i]);
            ans=max(ans, curr);

        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna