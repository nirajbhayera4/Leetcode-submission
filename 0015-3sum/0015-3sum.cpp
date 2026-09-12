
class Solution {
public:
    vector<vector<int>> result;

    void twosum(vector<int>& nums, int target, int i, int j) {
        while (i < j) {

            if (nums[i] + nums[j] > target) {
                j--;
            }
            else if (nums[i] + nums[j] < target) {
                i++;
            }
            else {
                // Found a valid pair

                // Remove duplicates
                while (i < j && nums[i] == nums[i + 1])
                    i++;

                while (i < j && nums[j] == nums[j - 1])
                    j--;

                result.push_back({-target, nums[i], nums[j]});

                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) {
            return {};
        }

        result.clear();

        sort(begin(nums), end(nums));

        // Fix the first number
        for (int i = 0; i <= n - 3; i++) {

            // Skip duplicate first numbers
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int n1 = nums[i];
            int target = -n1;

            twosum(nums, target, i + 1, n - 1);
        }

        return result;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna