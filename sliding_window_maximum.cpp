class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        if(v.empty()) {
            return {};
        }
        int n = v.size();
        deque < int > dq;

        for(int i = 0; i < k; i ++) {
            while(!dq.empty() and v[i] >= v[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector < int > ans = {v[dq.front()]};
        for(int i = k; i < n; i ++) {
            while(!dq.empty() and dq.front() <= i - k) {
                dq.pop_front();
            }
            while(!dq.empty() and v[i] >= v[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(v[dq.front()]);
        }
        return ans;
    }
};