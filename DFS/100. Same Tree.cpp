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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1,s2;
        TreeNode* proot = p;
        TreeNode* qroot = q;
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
//dfs
        while(proot != nullptr || !s1.empty() || qroot!=nullptr || !s2.empty()){
            while(proot || qroot){
                s1.push(proot);
                s2.push(qroot);
                if(proot == nullptr && qroot != nullptr)
                    return false;
                else if(qroot == nullptr && proot != nullptr)
                    return false;
                else if(proot->val != qroot->val)
                    return false;
                proot = proot->left;
                qroot = qroot->left;
            }

            proot = s1.top();
            s1.pop();
            qroot = s2.top();
            s2.pop();
            proot = proot->right;
            qroot = qroot->right;
        }

        return true;
    }
};
