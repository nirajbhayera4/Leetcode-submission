class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums), end(nums));
        vector<int> t(n,1);
        vector<int> p(n,-1);

        int maxl=0;
        int lastp=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] ==0){
                    if(t[i] < t[j] +1){
                        t[i]=t[j] +1;
                        p[i]=j;
                    }
                    if(t[i]> maxl){
                        maxl=t[i];
                        lastp=i;
                    }
                }
            }
        }
        vector<int> res;
        while(lastp!=-1){
            res.push_back(nums[lastp]);
            lastp=p[lastp];
        }
        return res;
    }
};