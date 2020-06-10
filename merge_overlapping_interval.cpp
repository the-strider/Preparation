/*
Merge overlapping interval in constant space
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        if(v.empty()) return {};

        int n = v.size();
        sort(v.begin(), v.end());
        
        int idx = 0;
        for(int i = 1; i < n; i ++) {
            if(v[idx][1] >= v[i][0]) {
                v[idx][0] = min(v[i][0], v[idx][0]);
                v[idx][1] = max(v[i][1], v[idx][1]);
            } else {
                idx ++;
                v[idx] = v[i];
            }
        }
        vector < vector < int > > ans;
        for(int i = 0; i <= idx; i ++) {
            ans.push_back(v[i]);
        }
        return ans;
    }
};