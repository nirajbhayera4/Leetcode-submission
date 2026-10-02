class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mp;
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum %k;
            if(rem <0) rem+=k;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna