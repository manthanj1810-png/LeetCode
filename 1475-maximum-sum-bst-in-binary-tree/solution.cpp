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
class NodeValue{
    public:
    int maxi,mini,sum;
    NodeValue(int mini,int maxi,int sum){
        this->maxi=maxi;
        this->mini=mini;
        this->sum=sum;
    }
};
class Solution {
public:
    int ans=0;
    NodeValue helper(TreeNode* root){
        if(root==NULL) return NodeValue(INT_MAX,INT_MIN,0);
        auto l=helper(root->left);
        auto r=helper(root->right);
        if(l.maxi< root->val && r.mini > root->val){
            int curr=l.sum + r.sum+root->val;
            ans=max(ans,curr);
            return NodeValue(min(root->val,l.mini),max(root->val,r.maxi),curr);
        }
        return NodeValue(INT_MIN,INT_MAX,0);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};
