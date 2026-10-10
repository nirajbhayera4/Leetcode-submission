class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            // agar left element mid se bda hoga to , humesha target/small element right side pe hoga/
            // right pe search krega 
             

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }

            // and vice versa hoga 
            // left pe search krega 
            else {
                r = mid;
            }
        }

        return nums[l];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna