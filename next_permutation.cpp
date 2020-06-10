class Solution {
public:
    void reverse(vector < int > &v, int st) {
        int n = v.size();
        int i = st, j = n - 1;
        while(i < j) {
            swap(v[i], v[j]);
            i ++, j --;
        }
    }

    void nextPermutation(vector<int>& v) {
        int n = v.size();
        int i = n - 2;
        // Find the first index from the end which is smaller than the previous
        while(i >= 0 and v[i] >= v[i + 1]) {
            i --;
        }
        if(i >= 0) {
            int j = n - 1;
            // Find the first index from the end which is larger than the ith element
            while(j >= 0 and v[j] <= v[i]) {
                j --;
            }
            // swap these two elements
            swap(v[i], v[j]);
        }
        // to find next permutation, reverse a[i+1 ... n]
        reverse(v, i + 1);
    }
};