/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Solution -> use first column and first row of the matrix to store if the ith row or jth col has 0
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        if(v.empty()) {
            return;
        }
        int n = v.size();
        int m = v[0].size();
        bool is_col = false;
        for(int i = 0; i < n; i ++) {
            is_col |= (v[i][0] == 0);
            for(int j = 1; j < m; j ++) {
                if(v[i][j] == 0) {
                    v[i][0] = 0;
                    v[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n; i ++) {
            for(int j = 1; j < m; j ++) {
                if(v[i][0] == 0 or v[0][j] == 0) {
                    v[i][j] = 0;
                }
            }
        }
        
        if(v[0][0] == 0) {
            for(int j = 0; j < m; j ++) {
                v[0][j] = 0;
            }
        }
        
        if(is_col) {
            for(int i = 0; i < n; i ++) {
                v[i][0] = 0;
            }
        }
    }
};