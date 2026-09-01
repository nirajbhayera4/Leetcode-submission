class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;
        // freq count kr lete h pehle 
        for(int x : nums){
            freq[x]++;
        }
        priority_queue<pair<int, int>> pq;



        // freq vector me traverse kr lenge
        for(auto &it : freq){
          
                pq.push({it.second, it.first});
            
        }

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna