// QUESTION LINK
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0,preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }

    TreeNode* build(vector<int>& pre, int preS, int preE, vector<int>& inO, int inS, int inE, map<int,int> mp) {
        if(preS>preE || inS>inE) return NULL;
        TreeNode* root = new TreeNode(pre[preS]);
        int inRoot = mp[root->val];
        int numLeft = inRoot-inS;

        root->left = build(pre, preS+1, preS+numLeft, inO, inS, inRoot-1, mp);
        root->right = build(pre, preS+numLeft+1, preE, inO, inRoot+1, inE, mp);
        return root;
    }
};
