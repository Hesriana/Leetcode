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
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root)
            return vector<int>{};
        
        vector<int> inorder;
        stack<TreeNode*> s;
        TreeNode* temp = root;

        while(temp != nullptr || !s.empty()){
            while(temp){
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            inorder.push_back(temp->val);
            temp = temp->right;
        }

        return inorder;
    }
};
