class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            char ch=s[i];
            arr[ch-'a']++;
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(arr[ch-'a']==1){
                return i;
            }
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna