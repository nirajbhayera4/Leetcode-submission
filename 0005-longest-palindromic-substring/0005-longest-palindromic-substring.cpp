class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0,maxlen=1;
        for(int i=0;i<n;i++){
            // odd size 
            expandAroundCenter(s,i,i,start,maxlen);

            // even size
            expandAroundCenter(s,i,i+1,start,maxlen);
        
        }
        return s.substr(start,maxlen);
    }
    private:
    void expandAroundCenter(const string& s,int left,int right,int &start,int &maxlen){
        int n=s.size();

        while(left >=0 && right < n && s[left]==s[right]){
            left--;
            right++;
        }

        int len=right - left -1;


        if(len > maxlen){
            maxlen=len;
            start=left +1;
        }
    }
};