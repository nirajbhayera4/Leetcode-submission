class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;
        while(i <j && s[i]==s[j]){
            char ch=s[i];

            //remove same char from left

            while(i <=j && s[i]==ch){
                i++;
            }

            // remove same char from right
            while(i <=j && s[j]==ch){
                j--;
            }
        }
        return j- i+1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna