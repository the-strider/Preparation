class Solution {
public:
    vector < vector < int > > func(vector < int > &v, int start, int target) 
    {
        vector < vector < int > > res;
        unordered_map < int, int > mp;

        for(int i = start; i < v.size(); i ++) {
            if(!res.empty() and v[i] == res.back()[1]) continue;
            if(mp.find(target - v[i]) != mp.end()) {
                res.push_back({target - v[i], v[i]});
            }
            mp[v[i]] = 1;
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        
        vector < vector < int > > ans;
        for(int i = 0; i < n; i ++) {
            if(i and v[i] == v[i - 1]) continue;
            vector < vector < int > > res = func(v, i + 1, -v[i]);
            
            for(auto x: res) {
                ans.push_back({v[i], x[0], x[1]});
            }
        }
        return ans;
    }
};