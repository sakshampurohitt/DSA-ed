// QUESTION LINK
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr = root;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();

            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);

            if(!s.empty()) curr->right = s.top();
            curr->left = NULL;
        }
    }
};
