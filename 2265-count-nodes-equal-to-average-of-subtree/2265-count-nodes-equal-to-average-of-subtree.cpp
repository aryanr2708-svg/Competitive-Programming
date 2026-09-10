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
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
private:
    pair<int,int> dfs(TreeNode* root, int& ans){
        if (root==nullptr){
            return {0,0};
        }
        auto[ls,lc]=dfs(root->left,ans);
        auto[rs,rc]=dfs(root->right,ans);
        int s=root->val+ls+rs;
        int c=1+lc+rc;
        if(s/c==root->val){
            ++ans;
        }
        return {s,c};
    }
};