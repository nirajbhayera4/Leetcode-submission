class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            // if token is a number , then push it into stack 
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }
            else{
                // if token is a operator 
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(tokens[i]=="+")st.push(a +b);
                else if(tokens[i]=="-")st.push(a-b);
                else if(tokens[i]=="*")st.push(a*b);
                else if(tokens[i]=="/")st.push(a/b);
            }
        }
        return st.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna