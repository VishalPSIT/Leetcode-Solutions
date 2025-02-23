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
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            stack<TreeNode*> st;
            int post = 0;
            TreeNode* root = new TreeNode(preorder[0]); 
            st.push(root);
    
            for (int i = 1; i < preorder.size(); i++) {
                TreeNode* node = new TreeNode(preorder[i]);
    
                // Attach as left or right child
                if (!st.top()->left) {
                    st.top()->left = node;
                } else {
                    st.top()->right = node;
                }
    
                st.push(node);
    
                // Pop when the top matches postorder (subtree complete)
                while (!st.empty() && st.top()->val == postorder[post]) {
                    st.pop();
                    post++;
                }
            }
            return root;
        }
    };