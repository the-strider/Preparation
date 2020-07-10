class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        if(v.empty()) {
            return 0;
        }
        int n = v.size();
        stack < int > st;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            ans = max(ans, v[i]);
            while(!st.empty() and v[st.top()] > v[i]) {
                int idx = st.top();
                st.pop();
                int start = st.empty() ? 0: st.top() + 1;
                ans = max(ans, (i - start) * v[idx]);
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            int idx  = st.top();
            st.pop();
            int start = st.empty() ? 0: st.top() + 1;
            ans = max(ans, (n - start) * v[idx]);
        }
        return ans;
    }
};