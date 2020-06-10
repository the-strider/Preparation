/* 
Given array of n + 1 integer and only one number is repeated multiple times 
1 <= v[i] <= n

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

// First solution -> Tortoise and hare | slow and fast pointer  (Two pass)
class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n = v.size();
        int a = v[0], b = v[0];
        do {
            a = v[a];       // slow pointer jump only one step
            b = v[v[b]];    // fast pointer jump two step
        } while(a != b);
        
        a = v[0];
        while(a != b) {
            a = v[a];
            b = v[b];
        }
        return a;
    }
};

// Second solution -> Making element negative   (One pass)
class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n = v.size();
        int ans = -1;
        for(int i = 0; i < n; i ++) {
            int x = abs(v[i]);
            if(v[x - 1] < 0) {
                ans = x;
                break;
            } 
            v[x - 1] = -v[x - 1];
        }
        return ans;
    }
};