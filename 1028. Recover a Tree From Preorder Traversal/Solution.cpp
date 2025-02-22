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
        // Function to extract the numerical value of a node from the traversal string
        int getValue(string traversal, int &i) {
            int val = 0;
            // Extract continuous digits and convert them into an integer
            while (i < traversal.size() && (traversal[i] >= '0' && traversal[i] <= '9')) {
                val = (val * 10) + (traversal[i] - '0');
                i++;
            }
            return val;
        }
        
        // Function to determine the depth of the current node based on the number of '-' characters
        int getDepth(string traversal, int &i) {
            int d = 0;
            // Count consecutive '-' characters which indicate the depth level
            while (i < traversal.size() && traversal[i] == '-') {
                i++;
                d++;
            }
            return d;
        }
        
        // Function to reconstruct the binary tree from the preorder traversal string
        TreeNode* recoverFromPreorder(string traversal) {
            TreeNode* root = nullptr; // Pointer to hold the root node
            stack<TreeNode*> stNode; // Stack to maintain node hierarchy during tree reconstruction
            int i = 0; // Index to iterate through the traversal string
            
            while (i < traversal.size()) {
                int depth = getDepth(traversal, i); // Determine the depth of the current node
                int val = getValue(traversal, i); // Extract the value of the current node
                
                TreeNode* newNode = new TreeNode(val); // Create a new tree node with the extracted value
                
                // Ensure the stack contains only nodes at the correct depth level
                while (depth < stNode.size()) {
                    stNode.pop(); // Remove nodes from the stack until we reach the parent level
                }
                
                // If the stack is not empty, attach the new node as a left or right child
                if (!stNode.empty()) {
                    if (stNode.top()->left == nullptr) {
                        stNode.top()->left = newNode; // Assign as left child if vacant
                    } else {
                        stNode.top()->right = newNode; // Otherwise, assign as right child
                    }
                } else {
                    root = newNode; // If the stack is empty, this node is the root
                }
                
                stNode.push(newNode); // Push the new node onto the stack
            }
            
            return root; // Return the reconstructed tree's root
        }
};
    