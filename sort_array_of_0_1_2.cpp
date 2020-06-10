class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int i = 0, zero_idx = 0, two_idx = n - 1;
        while(i <= two_idx) {
            if(v[i] == 0) {
                swap(v[i], v[zero_idx]);
                zero_idx ++;
                i ++;
            } else if(v[i] == 2) {
                swap(v[i], v[two_idx]);
                two_idx --;
            } else {
                i ++;
            }
        }
    }
};