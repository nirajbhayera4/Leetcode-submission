class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;

        int n=numbers.size();
        while(i <j){
            int sum=numbers[i] + numbers[j];
            if(sum ==target){
                return {i +1,j+1};
            }
            else if(sum < target){
                i++;
                

            }
            else{
                j--;
            }
            
        }
        return {};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna