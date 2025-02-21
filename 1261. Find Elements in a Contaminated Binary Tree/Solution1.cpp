/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

 class FindElements {
    public:
        unordered_set<int> node; // Stores all valid node values after recovery
    
        /**
         * Recursively recovers the tree and stores node values in the set.
         * @param root The current node being processed.
         * @param value The computed value of the current node.
         */
        void solve(TreeNode* root, int value) {
            if (root == nullptr)
                return;
            node.insert(value); // Store the recovered value
            solve(root->left, 2 * value + 1); // Recur for the left child
            solve(root->right, 2 * value + 2); // Recur for the right child
        }
    
        /**
         * Constructor: Recovers the tree from a contaminated state.
         * @param root The root of the contaminated tree.
         */
        FindElements(TreeNode* root) {
            if (root) {
                root->val = 0; // The root node is always set to 0
                node.insert(0); // Store the root value
            }
            solve(root, 0); // Start recovery process
        }
    
        /**
         * Checks if a given target value exists in the recovered tree.
         * @param target The value to search for.
         * @return True if the value exists, false otherwise.
         */
        bool find(int target) { 
            return node.find(target) != node.end(); 
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */
    