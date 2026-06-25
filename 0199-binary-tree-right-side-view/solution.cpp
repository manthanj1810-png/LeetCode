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
    vector<int> rightSideView(TreeNode* root) {
       map<int,int> mp;
       queue<pair<TreeNode*,int>> q;
       if(root) q.push({root,0});
       while(!q.empty()){
        auto [node,lev]=q.front();
        q.pop();
        mp[lev]=node->val;
        if(node->left) q.push({node->left,lev+1});
        if(node->right) q.push({node->right,lev+1});
       } 
       vector<int> ans;
       for(auto it:mp){
        ans.push_back(it.second);
       }
       return ans;
    }
};
