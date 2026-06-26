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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++) inMap[inorder[i]]=i;
        TreeNode* root= buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,int pres,int pree, vector<int>& inorder,int ins,int ine,map<int,int> &inMap){
        if(pres>pree || ins>ine) return NULL;
        TreeNode* root=new TreeNode(preorder[pres]);
        int inr=inMap[root->val];
        int x= inr-ins;
        root->left= buildTree(preorder,pres+1,pres+x,inorder,ins,inr-1,inMap);
        root->right= buildTree(preorder,pres+1+x,pree,inorder,inr+1,ine,inMap);
        return root;
    }
};
