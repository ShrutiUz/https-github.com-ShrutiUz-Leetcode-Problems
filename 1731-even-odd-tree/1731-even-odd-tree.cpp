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
    bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) return true;

        queue<TreeNode*>q;
        q.push(root);

        bool even = true;

        while(!q.empty()){

            int size = q.size();

            int preVal = even? INT_MIN : INT_MAX;

            while(size--){
                TreeNode* node = q.front();
                q.pop();

                if(even && (node->val%2==0 || node->val <= preVal)) return false;
                if(!even && (node->val%2==1 || node->val >= preVal)) return false;

                preVal = node->val;
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }

            even = !even;
        }

        return true;
    }
};