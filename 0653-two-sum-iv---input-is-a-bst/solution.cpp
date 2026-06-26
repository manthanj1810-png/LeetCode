/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class iteratorbst{
public:
    stack<TreeNode*> st;
    bool reverse;
    iteratorbst(TreeNode* root,bool isreverse){
        reverse=isreverse;
        pushall(root);
    }
    bool has(){
        return !st.empty();
    }
    int next(){
        TreeNode *temp=st.top();
        st.pop();
        if(reverse){
            pushall(temp->left);
        }
        else pushall(temp->right);
        return temp->val;
    }
    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            if(reverse) root=root->right;
            else root=root->left;
        }
    }
};
class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
       iteratorbst n(root,false);
       iteratorbst b(root,true);
       int i=n.next(),j=b.next();
       while(i<j){
        if(i+j==k) return true;
        else if(i+j<k) i=n.next();
        else j=b.next();
       }
       return false; 
    }
};
