class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int i = 0;

        for(int j = 0; j < nums.size(); j++) {

            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna