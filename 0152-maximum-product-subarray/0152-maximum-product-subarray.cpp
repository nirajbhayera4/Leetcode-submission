class Solution {
public:
int solve(vector<int>& nums){
    int n=nums.size();
    if(n==0)return 0;

    int curr_max=nums[0];
    int curr_min=nums[0];
    int res=nums[0];

    for(int j=1;j<n;j++){
        int temp=curr_max;

        curr_max=max({nums[j],temp * nums[j], curr_min *nums[j]});
        curr_min=min({nums[j],temp * nums[j], curr_min *nums[j]});
        res=max(curr_max,res);
    }
    return res;
}
    int maxProduct(vector<int>& nums) {
        
        return solve(nums);
    }
};