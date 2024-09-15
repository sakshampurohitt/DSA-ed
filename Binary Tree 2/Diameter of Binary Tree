// QUESTION LINK
// https://leetcode.com/problems/diameter-of-binary-tree/
class Solution {
public:
    int diameter(TreeNode* root, int &res) {
        if(!root) return 0;
        int left = diameter(root->left, res);
        int right = diameter(root->right, res);

        res = max(res, left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameter(root, res);
        return res;
    }
};
