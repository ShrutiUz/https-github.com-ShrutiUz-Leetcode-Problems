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

    pair<int,int>solve(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        int left_sum = left.first;
        int left_count = left.second;

        int right_sum = right.first;
        int right_count = right.second;

        int sum = left_sum + right_sum + root->val;
        int count = left_count + right_count + 1;

        if(root->val == sum/count){
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};