class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> minleft(n), maxright(n);
        // precompute the sum 
        // we can make prefix sum array

        minleft[0]=nums[0];
        for(int i=1;i<n;i++){
            minleft[i]=min(minleft[i-1], nums[i]);
        }

        // we can also suffix sum array 
        maxright[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            maxright[j]=max(maxright[j+1],nums[j]);
        }

        // two pointer scan
        int i=0,j=0,ans=0;
        while(i <n && j<n){
            if(minleft[i] <= maxright[j]){
                ans=max(ans,j-i);
                j++;
            }
            else{
                i++;
            }

        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna