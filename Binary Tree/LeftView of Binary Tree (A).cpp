// QUESTION SIZE
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.

void preOrder(Node* root, int level, vector<int>& res) {
    if(root==NULL) return;
    
    if(res.size()==level)
        res.push_back(root->data);
    
    preOrder(root->left, level+1, res);
    preOrder(root->right, level+1, res);
}

vector<int> leftView(Node *root)
{
    if(root==NULL) return {};
    vector<int> res;
    preOrder(root, 0, res);
    return res;
}
