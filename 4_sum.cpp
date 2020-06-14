/* Generalisation for k-sum problem */

class Solution {
public:
    vector < vector < int > > twoSum(vector < int > &v, int start, int target) {
        int n = v.size();
        unordered_map < int, int > mp;
        vector < vector < int > > res;

        for(int i = start; i < n; i ++) {
            if(!res.empty() and v[i] == res.back()[1]) continue;
            if(mp.find(target - v[i]) != mp.end()) {
                res.push_back({target - v[i], v[i]});
            }
            mp[v[i]] = 1;
        }
        return res;
    }
    
    // Generalising for ksum problem
    vector < vector < int > > ksum(vector < int > &v, int start, int k, int target) {
        if(start == v.size() or v[start] * k > target or target > v.back() * k) {
            /* if k smallest value is bigger than target or k larget 
            value is less than target than target can't be formed */
            return {};
        }
        if(k == 2) {
            return twoSum(v, start, target);
        }
        vector < vector < int > > res;
        for(int i = start; i < v.size(); i ++) {
            if(i != start and v[i] == v[i - 1]) continue;
            vector < vector < int > > new_res = ksum(v, i + 1, k - 1, target - v[i]);
            for(auto p: new_res) {
                vector < int > temp(1, v[i]);
                temp.insert(temp.end(), p.begin(), p.end());
                res.push_back(temp);
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& v, int target) {
        sort(v.begin(), v.end());
        return ksum(v, 0, 4, target);
    }
};