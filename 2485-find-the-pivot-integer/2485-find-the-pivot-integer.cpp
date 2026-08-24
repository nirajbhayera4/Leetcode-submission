class Solution {
public:
    int pivotInteger(int n) {
        int sum=n * (n +1)/2;
        int x=sqrt(sum);

        return x * x==sum ? x:-1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna