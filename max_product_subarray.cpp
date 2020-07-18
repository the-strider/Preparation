class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        int mi = v[0], ma = v[0];
        int ans = v[0];
        for(int i = 1; i < n; i ++) {
            int a = min({v[i], mi * v[i], ma * v[i]});
            int b = max({v[i], mi * v[i], ma * v[i]});
            ans = max({ans, a, b});
            mi = a;
            ma = b;
        }
        return ans;
    }
};