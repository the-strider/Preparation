/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Solution -> like 4 sum
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(v.begin(), v.end());

        int n = v.size();

        auto func = [&](int idx, int target, auto &func) -> vector < vector < int > > {
            if(idx == n or target == 0) {
                return {};
            }
            vector < vector < int > > res;

            for(int i = idx; i < n; i ++) {
                if(i != idx and v[i] == v[i - 1]) continue;
                if(target < v[i]) continue;
                if(target == v[i]) {
                    res.push_back({v[i]});
                }
                vector < vector < int > > ans = func(i + 1, target - v[i], func);

                for(auto p: ans) {
                    vector < int > temp(1, v[i]);
                    for(auto x: p) {
                        temp.push_back(x);
                    }
                    res.push_back(temp);
                }
            }            
            
            return res;
        };
        return func(0, target, func);
    }
};