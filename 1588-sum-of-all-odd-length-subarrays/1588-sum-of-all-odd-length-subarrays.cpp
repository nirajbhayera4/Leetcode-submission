class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                int len=j-i+1;

                if(len % 2==1){
                    for(int k=i;k<=j;k++){
                        sum+=arr[k];

                    }

                }
            }
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna