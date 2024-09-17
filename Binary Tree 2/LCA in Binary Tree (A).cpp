// QUESTION LINK
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q||!root) return root;
        TreeNode* lca_left = lowestCommonAncestor(root->left, p, q);
        TreeNode* lca_right = lowestCommonAncestor(root->right, p, q);
        if(lca_left && lca_right) return root;
        else return lca_left ? lca_left: lca_right;
    }
};
