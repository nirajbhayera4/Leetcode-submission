
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> t1;

        for(char c : s) {
            if(c == '#') {
                if(!s1.empty()) {
                    s1.pop();
                }
            }
            else {
                s1.push(c);
            }
        }

        for(char c : t) {
            if(c == '#') {
                if(!t1.empty()) {
                    t1.pop();
                }
            }
            else {
                t1.push(c);
            }
        }

        return s1 == t1;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna