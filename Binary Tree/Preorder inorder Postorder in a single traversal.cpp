// QUESTION LINK
// https://www.naukri.com/code360/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=SUBMISSION

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    if(!root) return {{}};
    vector<int> pre, inO, post;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while(!st.empty()) {
        auto it = st.top();
        st.pop();
        //Preorder
        if(it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left)
                st.push({it.first->left, 1});
        }
        else if(it.second == 2) {
            inO.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right) 
                st.push({it.first->right, 1});
        }
        else {
            post.push_back(it.first->data);
        }
    }
    return {inO, pre, post};
}
