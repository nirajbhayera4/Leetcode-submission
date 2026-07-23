class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (int num : nums) {
            int curr = max(b, a + num);
            a=b;
            b= curr;
        }
        return b;
    }
};