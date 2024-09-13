// QUESTION LINK
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if(root==NULL) return {};
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            Node* node = temp.first;
            int line = temp.second;
            mp[line] = node->data;
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        
        for(auto it: mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
