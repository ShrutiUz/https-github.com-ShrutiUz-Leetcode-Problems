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
    void preorder(TreeNode* root, vector<int>&ans){
        if(root == NULL){
            return;
        }
        preorder(root->left, ans);
        ans.push_back(root->val);
        preorder(root->right, ans);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        preorder(root, ans);

        unordered_map<int, int>freq;
        int maxx = 0;

        for(int node: ans){
            freq[node]++;
            maxx = max(maxx, freq[node]);
        }

        vector<int>result;

        for(auto it: freq){
            if(it.second == maxx){
                result.push_back(it.first);
            }
        }

        return result;
        
    }
};