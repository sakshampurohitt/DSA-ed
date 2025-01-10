class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            res.push_back(curr->val);
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }
        return res;
    }
};
