class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextGreater;
        stack<int> s;
        for(int num :nums2){
            while(!s.empty() && num >s.top()){
                nextGreater[s.top()]=num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> result;
        for(int num :nums1){
            result.push_back(nextGreater.count(num)? nextGreater[num] :-1);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna