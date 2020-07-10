class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector < vector < string > > ans;
        vector < string > v(n, string(n, '.'));
        
        vector < int > row(2 * n), col(2 * n), dig_up(2 * n), dig_down(2 * n);

        auto dfs = [&](int idx, auto &dfs) -> void {
            if(idx == n) {
                ans.push_back(v);
                return;
            }
            
            for(int j = 0; j < n; j ++) {
                if(row[idx] or col[j] or dig_up[n + idx - j] or dig_down[idx + j]) continue;
                row[idx] = col[j] = dig_up[n + idx - j] = dig_down[idx + j] = 1;
                v[idx][j] = 'Q';
                dfs(idx + 1, dfs);
                v[idx][j] = '.';
                row[idx] = col[j] = dig_up[n + idx - j] = dig_down[idx + j] = 0;
            }
        };
        
        dfs(0, dfs);
        return ans;
    }
};