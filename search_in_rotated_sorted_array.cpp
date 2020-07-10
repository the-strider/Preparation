class Solution {
public:
    int search(vector<int>& v, int target) {
        if(v.empty()) {
            return -1;
        }
        int n = v.size();
        
        int low = 0, high = n - 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(v[mid] == target) {
                return mid;
            }
            if(v[low] <= v[mid]) {  // search in left sorted array [low .. mid]
                if(target > v[mid] or target < v[low]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {               // search in right sorted array [mid .. high]
                if(target < v[mid] or target > v[high]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};