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
    bool ans =  true;
    long long  val = INT_MIN-1LL;
    void check(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        check(root->left);
        if(root->val <= val){
            ans = false;
        }
        else{
            val = root->val;
        }
        check(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right)
        {
            return true;
        }
        check(root);
        return ans;
    }
};