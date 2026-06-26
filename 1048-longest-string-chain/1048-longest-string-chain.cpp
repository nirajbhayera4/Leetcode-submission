

class Solution {
public:
    int n;
    int t[1001][1001];
    static bool myFunction(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    bool isPred(string& prev, string& curr) {
        int M = prev.length();
        int N = curr.length();
        if (M >= N || N - M != 1) {
            return false;
        }

        int i = 0, j = 0;
        while (i < M && j < N) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i == M;
    }

    int solve(vector<string>& words, int p, int i) {
        if (i == n)
            return 0;

        if(p!=-1 && t[p][i] !=-1){
            return t[p][i];
        }
        int take=0, skip=0;

        if (p == -1 || isPred(words[p], words[i])) {
            take = 1 + solve(words, i, i+1);
        }
        skip = solve(words,p, i + 1);

        if(p !=-1){
            return t[p][i]=max(take,skip);
        }

        return max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(t,-1,sizeof(t));
        sort(begin(words), end(words), myFunction);
        return solve(words, -1, 0);
    }
};