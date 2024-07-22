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
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* ans = root;

        if(ans->val == val)
            return ans;

        while(ans != nullptr && val != ans->val){
            
            cout << ans -> val << endl;
            
            if(val > ans->val)
                ans = ans->right;
            else if(val < ans->val)
                ans = ans->left;
            
            if(ans == nullptr)
                break;
            
            if(ans->val == val){   
                return ans;
                break;
            }
        }

        return nullptr;
    }
};
