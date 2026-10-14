class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=l + (r-l)/2;
             arr[mid]=arr[mid]-(mid+1);
            if(arr[mid]<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l+k;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna