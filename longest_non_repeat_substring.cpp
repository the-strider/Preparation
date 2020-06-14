/*
Given a string, find the length of the longest substring without repeating characters
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector < int > mp(256, -1);
        int n = s.length();
        int prev = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            int idx = s[i];
            if(mp[idx] >= prev) {
                ans = max(ans, i - prev);
                prev = mp[idx] + 1;
            }
            mp[idx] = i;
        }
        ans = max(ans, n - prev);
        return ans;
    }
};