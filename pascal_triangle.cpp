class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(!n) return {};
        
        vector < vector < int > > ans(1, vector < int > (1, 1));
        for(int i = 1; i < n; i ++) {
            vector < int > temp(1, 1);
            for(int j = 1; j < ans[i - 1].size(); j ++) {
                temp.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};