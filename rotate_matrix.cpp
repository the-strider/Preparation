class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        if(v.empty()) {
            return;
        }
        int n = v.size();
        
        int last = n - 1;
        for(int i = 0; i < n / 2; i ++) {
            for(int j = i; j < last - i; j ++) {
                int a = last - i;
                int b = last - j;

                int w = v[i][j];
                int x = v[j][a];
                int y = v[a][b];
                int z = v[b][i];
                v[j][a] = w;
                v[a][b] = x;
                v[b][i] = y;
                v[i][j] = z;
            }
        }
    }
};