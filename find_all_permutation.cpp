class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        if(v.empty()) return {};
        vector < vector < int > > ans;
        int n = v.size();

        auto perm = [&] (int idx, auto &perm) -> void {
            if(idx == n) {
                ans.push_back(v);
                return;
            }

            for(int i = idx; i < n; i ++) {
                swap(v[i], v[idx]);
                // increment idx by one
                perm(idx + 1, perm);
                swap(v[i], v[idx]);
            }
        };

        perm(0, perm);
        return ans;
    }
};