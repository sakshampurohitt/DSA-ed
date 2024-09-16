// QUESTION LINK
// https://leetcode.com/problems/balanced-binary-tree/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(height(root)==-1) return false;
        return true;
    }
    int height(TreeNode* root) {
        if(!root) return 0;
        int lH = height(root->left);
        if(lH==-1) return -1;
        int rH = height(root->right);
        if(rH==-1) return -1;
        if(abs(rH-lH) > 1) return -1;
        return max(rH,lH)+1;
    }
};
