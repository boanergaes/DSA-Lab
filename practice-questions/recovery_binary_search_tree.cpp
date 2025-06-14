#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
    void traverse(TreeNode* root, vector<TreeNode*>& traversed){
        if (!root) return;
        if (root->left) traverse(root->left, traversed);
        traversed.push_back(root);
        if (root->right) traverse(root->right, traversed);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> trv;
        traverse(root, trv);
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* prev = nullptr;

        for (auto node : trv) {
            if (prev && prev->val > node->val) {
                if (!x) x = prev; // first bad node
                y = node;          // last bad node
            }
            prev = node;
        }
        int temp = x->val;
        x->val = y->val;
        y->val = temp;

    }
};

int main() {
    return 0;
}