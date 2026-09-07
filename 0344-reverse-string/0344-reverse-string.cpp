class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();

        int i = 0;
        int j = n - 1;

        while (i < j) {
            int temp = s[j];
            s[j] = s[i];
            s[i] = temp;

            i++;
            j--;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna