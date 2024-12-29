class Solution {
  public:
    Node* merge(Node* a, Node* b) {
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(a && b) {
            if(a->data < b->data) {
                res->bottom = a;
                res = a;
                a = a->bottom;
            }
            else {
                res->bottom = b;
                res = b;
                b = b->bottom;
            }
            res->next=nullptr;
        }
        if(a) res->bottom=a;
        if(b) res->bottom=b;
        
        if(dummy->bottom) {
            dummy->bottom->next=nullptr;
        }
        return dummy->bottom;
    }
    // Function which returns the root of the flattened linked list.
    Node *flatten(Node *root) {
        if(!root || !root->next) return root;
        
        Node* mergedHead = flatten(root->next);
        root = merge(root, mergedHead);
        return root;
    }
};
