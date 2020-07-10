class Solution {
public:

    int compareVersion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int i = 0, j = 0;
        
        while(i < n or j < m) {
            int x = 0, y = 0;
            while(i < n and s1[i] != '.') {
                x = x * 10 + (s1[i] - '0');
                i ++;
            }
            while(j < m and s2[j] != '.') {
                y = y * 10 + (s2[j] - '0');
                j ++;
            }
            
            if(x > y) return 1;
            if(x < y) return -1;
            i ++;
            j ++;
        }
        return 0;
    }
};