class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums), end(nums));
        int i=0;
        int j=n-1;
        int ans=0;
        
        while(i <j){
            int sum=nums[i] + nums[j]; //8
            ans=max(ans,sum);
            i++;
            j--;


        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna