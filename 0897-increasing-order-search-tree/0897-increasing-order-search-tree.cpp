
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {

        stack<TreeNode*> st;
        vector<TreeNode*> nodes;

        TreeNode* curr = root;

        // Step 1: Iterative inorder traversal
        while(curr != nullptr || !st.empty()) {

            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            nodes.push_back(curr);

            curr = curr->right;
        }

        // Step 2: Rearrange pointers
        for(int i = 0; i < nodes.size(); i++) {

            nodes[i]->left = nullptr;

            if(i + 1 < nodes.size()) {
                nodes[i]->right = nodes[i + 1];
            }
            else {
                nodes[i]->right = nullptr;
            }
        }

        // Step 3: Return new root
        return nodes.empty() ? nullptr : nodes[0];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna