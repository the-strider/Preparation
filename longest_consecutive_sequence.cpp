class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        unordered_map < int, int > mp;
        for(auto x: v) {
            mp[x] = 1;
        }
        int ans = 0;
        for(auto x: mp) {
            if(mp.count(x.first - 1) > 0) {
                continue;
            }

            int cnt = 1;
            int val = x.first + 1;
            while(mp.count(val) > 0) {
                cnt ++;
                val ++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};