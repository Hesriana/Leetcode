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
    bool isSymmetric(TreeNode* root) {

//把樹切成左右兩邊，然後右邊的樹利用dfs跑到底(左邊到底的dfs)，左邊的樹則是利用右邊到底的dfs去跑，不這麼做兩邊不能鏡像去比對        
        stack<TreeNode*> sr,sl;//left tree sl,right tree sr
        TreeNode* rnode = root->right;
        TreeNode* lnode = root->left;

        while(!sr.empty()) sr.pop();
        while(!sl.empty()) sl.pop();

        while(!sr.empty() || rnode != nullptr || !sl.empty() || lnode != nullptr){
            while(rnode || lnode){
                sr.push(rnode);
                sl.push(lnode);

                if(rnode == nullptr && lnode != nullptr)
                    return false;
                else if(rnode != nullptr && lnode == nullptr)
                    return false;
                else if(rnode->val != lnode->val)
                    return false;
                
                rnode = rnode->left;//右邊先dfs跑左
                lnode = lnode->right;//左邊則相反
            }
            rnode = sr.top();
            lnode = sl.top();
            sr.pop();
            sl.pop();
            rnode = rnode->right;
            lnode = lnode->left;
        }
        
        return true;
    }
};