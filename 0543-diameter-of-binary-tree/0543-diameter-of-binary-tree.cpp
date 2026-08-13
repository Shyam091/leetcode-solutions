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
    int ans = INT_MIN;
    int checkDiameter(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int left= 0;
        int right = 0;
        left+=checkDiameter(root->left);
        right+=checkDiameter(root->right);
        ans = max(ans , left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        checkDiameter(root);
        return ans;
        
    }
};