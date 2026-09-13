class Solution {
public:

    int numSubseq(vector<int>& nums, int target) {
        const int mod=1e9 +7;
        sort(begin(nums), end(nums));
        int n=nums.size();
        vector<long long > power(n);
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1] *2)%mod;

        }
        int l=0,r=n-1;
        long long ans=0;
        while(l <=r){
            if(nums[l] + nums[r] <=target){
                ans=(ans+ power[r-l])%mod;
                l++;
            } 
            else{
                r--;
            }
        }
        return ans;
        


        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna