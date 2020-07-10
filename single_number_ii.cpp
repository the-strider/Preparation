/*
Given a non-empty array of integers, every element appears three times except for one,
which appears exactly once. Find that single one.
*/

class Solution {
public:
    int singleNumber(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int result = 0;
        for(int i = 0; i < 32; i ++) {
            int mask = (1 <<  i);
            int cnt = 0;
            for(auto x: v) {
                if(x & mask) {
                    cnt ++;
                }
            } 
            if(cnt % 3) {
                // cnt % 3 will always be either 0 or 1 never 2 because number occur only 3 times
                // and there will be only 1 number which occur 1 time.
                result |= mask;
            }
        }
        return result;
    }
};