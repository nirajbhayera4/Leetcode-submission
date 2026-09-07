class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        if(nums.empty())return 0;
        int k=1;
        for(int i=1;i<nums.size();i++){
           
            if(nums[i]!=nums[i-1]){
                nums[k]=nums[i];
                k++;

            
           }
        }
        return k;
        */
        if (nums.empty()) return 0;

        int i = 0;
        int j = 1;

        while (j < nums.size()) {

            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }

            j++;
        }

        return i + 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna