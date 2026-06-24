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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode*> q;
        vector<vector<int>> ans;
        bool lr=true;
        if(root) q.push(root);
        while(!q.empty()){
            int n=q.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            auto node= q.front();
            q.pop();
            int ind= lr ? i:n-1-i;
            temp[ind]=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        lr=!lr;
        ans.push_back(temp);
        }
        return ans;
    }
};
