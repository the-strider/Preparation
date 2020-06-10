// Given an array of n integers find all duplicates, 0 <= v[i] <= n - 1
class Solution {
	vector<int> duplicates(int v[], int n) {
	    vector < int > ans;
	    for(int i = 0; i < n; i ++) {
	        int idx = v[i] % n;
	        v[idx] += n;
	    }
	    
	    for(int i = 0; i < n; i ++) {
	        if(v[i] >= 2 * n) {
	            ans.push_back(i);
	        }
	    }
	    
	    if(ans.empty()) ans = {-1};
	    return ans;
	}
};