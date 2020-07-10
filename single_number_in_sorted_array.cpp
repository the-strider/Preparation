/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Find this single element that appears only once.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        if(v.empty()) {
            return 0;
        }

        int n = v.size();
        int low = 0, high = n - 1;
        
        while(low < high) {
            int mid = (low + high) / 2;
            if(v[mid] == v[mid ^ 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return v[low];
    }
};