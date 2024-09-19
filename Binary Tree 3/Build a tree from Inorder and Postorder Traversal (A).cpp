// QUESTION LINK
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]]=i;
        }
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }

    TreeNode* build(vector<int>&inO, int inS, int inE, vector<int>&postO, int postS, int postE, map<int,int>&mp)
    {
        if(inS>inE || postS>postE) return NULL;
        TreeNode* root = new TreeNode(postO[postE]);
        int inRoot = mp[root->val];
        int numLeft = inRoot - inS;

        root->left = build(inO, inS, inRoot-1, postO, postS, postS+numLeft-1, mp);
        root->right = build(inO, inRoot+1, inE, postO, postS+numLeft, postE-1, mp);
        return root;
    }
};
