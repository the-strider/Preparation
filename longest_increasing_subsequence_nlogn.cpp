class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        if(v.empty()) {
            return 0;
        }

        vector < int > dp(1, v[0]);
        int len = 1;
        int n = v.size();
        for(int i = 1; i < n; i ++) {
            int idx = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();

            if(idx == len) {
                dp.push_back(v[i]);
                len ++;
            } else {
                dp[idx] = v[i];
            }
        }
        return len;
    }
};