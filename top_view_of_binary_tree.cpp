class Solution {
    void topView(struct Node *root) {
        if(!root) {
            return {};
        }

        map < int, int > mp;
        queue < pair < Node *, int > > q;
        q.push({root, 0});
        
        while(!q.empty()) {
            pair < Node *, int > p = q.front();
            q.pop();
            
            int depth = p.second;
            Node * curr = p.first;
            
            if(mp.find(depth) == mp.end()) {
                mp[depth] = curr -> data;
            }
            
            if(curr -> left) q.push({curr -> left, depth - 1});
            if(curr -> right) q.push({curr -> right, depth + 1});
        }
        
        vector < int > ans;
        for(auto x: mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
}