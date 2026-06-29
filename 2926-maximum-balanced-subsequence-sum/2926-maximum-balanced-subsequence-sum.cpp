#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i] - i;
        }
        
        map<int, long long> mp;
        long long ans = LLONG_MIN;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                ans = max(ans, (long long)nums[i]);
            } else {
                long long temp = nums[i];
                // Find the largest key <= arr[i]
                auto it = mp.upper_bound(arr[i]);
                if (it != mp.begin()) {
                    --it;
                    temp += it->second;
                }
                
                // Remove entries with key >= arr[i] that have smaller sum than temp
                while (!mp.empty()) {
                    auto ceiling_it = mp.lower_bound(arr[i]);
                    if (ceiling_it != mp.end() && ceiling_it->second < temp) {
                        mp.erase(ceiling_it);
                    } else {
                        break;
                    }
                }
                
                // Add current entry if it's better than existing ones with key <= arr[i]
                auto floor_it = mp.upper_bound(arr[i]);
                if (floor_it == mp.begin() || (--floor_it)->second < temp) {
                    mp[arr[i]] = temp;
                }
                
                ans = max(ans, temp);
            }
        }
        
        return ans;
    }
};