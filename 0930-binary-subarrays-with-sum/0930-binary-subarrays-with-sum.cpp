class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int x : nums){
            sum +=x;

            if(mp.find(sum -goal )!=mp.end()){
                ans+=mp[sum - goal];
            }
            mp[sum]++;
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna