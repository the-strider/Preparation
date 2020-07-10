class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        if(v.empty()) {
            return 0;
        }

        int idx = 1;
        int n = v.size();
        for(int i = 1; i < n; i ++) {
            if(v[i] != v[i - 1]) {
                v[idx] = v[i];
                idx ++;
            }
        }

        // Delete all duplicates
        while(n > idx) {
            v.pop_back();
            n --;
        }
        return idx;
    }
};