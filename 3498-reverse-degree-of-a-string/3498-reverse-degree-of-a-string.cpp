class Solution {
public:
    int reverseDegree(string s) {
        int n = 0;
        for(int i=0;i<s.length();i++)
        {
            n+=(i+1)*(26-(s[i]-'a'));
        }
        return n;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna