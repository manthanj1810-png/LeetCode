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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++) inMap[inorder[i]]=i;
        TreeNode* root= buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& postorder,int posts,int poste, vector<int>& inorder,int ins,int ine,map<int,int> &inMap){
        if(posts>poste || ins>ine) return NULL;
        TreeNode* root=new TreeNode(postorder[poste]);
        int inr=inMap[root->val];
        int x= inr-ins;
        root->left= buildTree(postorder,posts,posts+x-1,inorder,ins,inr-1,inMap);
        root->right= buildTree(postorder,posts+x,poste-1,inorder,inr+1,ine,inMap);
        return root;
    }
};
