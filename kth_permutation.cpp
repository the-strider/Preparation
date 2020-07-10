/*
The idea is as follow:

For permutations of n, the first (n-1)! permutations start with 1, next (n-1)! ones start with 2, ... and so on. 
And in each group of (n-1)! permutations, the first (n-2)! permutations start with the smallest remaining number.

*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        vector < int > fact(1, 1);

        for(int i = 1; i <= n; i ++) {
            s += (i + '0');
            fact.push_back(fact[i - 1] * i);
        }
        
        k --;
        string res = "";
        while(n > 0) {
            n --;
            int idx = k / fact[n];
            k = k % fact[n];
            res += s[idx];
            s.erase(idx, 1);
        }
        return res;
    }
};