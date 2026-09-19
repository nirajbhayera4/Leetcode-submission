class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minp=-1;
        int maxp=-1;
        int cultidx=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < minK || nums[i] > maxK){
                cultidx=i;
            }

            if(nums[i]==minK)minp=i;
            if(nums[i]==maxK)maxp=i;

            long long smaller=min(minp, maxp);
            long long temp=smaller - cultidx;
            ans+=(temp <=0)? 0 : temp;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna