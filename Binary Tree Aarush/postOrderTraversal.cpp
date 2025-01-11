class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*>s1, s2;
        s1.push(root);

        while(!s1.empty()) {
            TreeNode* curr = s1.top();
            s1.pop();
            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
            s2.push(curr);
        }
        vector<int> ans;
        while(!s2.empty()) {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};
