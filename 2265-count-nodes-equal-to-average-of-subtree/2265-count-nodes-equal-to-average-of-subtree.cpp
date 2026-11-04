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
    int ans = 0;
    pair<int,int>  backtrack(TreeNode* root)
    {
        if(!root) return {0,0};
       auto [xl , nl] =  backtrack(root->left ) ;
       auto [xr , nr] = backtrack(root->right );

       if( !root->left && !root->right )
       {
        ans++;
        return {root->val, 1} ;
       }

       if((xl + xr + root->val ) / (nl+nr+1) == root->val) ans++;

       return {xl+xr+root->val,nl+nr+1};

    }




    
    int averageOfSubtree(TreeNode* root) {
        backtrack(root);
        return ans;
    }
};