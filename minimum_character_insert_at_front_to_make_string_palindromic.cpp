class Solution {
public:
    vector < int > computeLPS(string &s) {
        int n = s.length();
        vector < int > lps(n, 0);
        int len = 0;
        int i = 1;
        while(i < n) {
            if(s[i] == s[len]) {
                lps[i ++] =  ++ len;
            } else {
                if(len != 0) len = lps[len - 1];
                else lps[i ++] = 0;
            }
        }
        return lps;
    }

    string shortestPalindrome(string s) {
        string prev = s;
        string rev = s;

        reverse(rev.begin(), rev.end());
        s = s + "#" + rev;
        
        vector < int > lps = computeLPS(s);
        
        string res = rev.substr(0, prev.length() - lps.back()) + prev;
        return res;
    }
};
