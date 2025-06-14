#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
    pair<TreeNode*, int> lca_finder(TreeNode* root) {
        if (root == nullptr) return {nullptr, 0};

        auto left = lca_finder(root->left);
        auto right = lca_finder(root->right);

        if (left.second > right.second) return {left.first, left.second + 1};
        if (right.second > left.second) return {right.first, right.second + 1};
        return {root, left.second + 1};
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto low_com_anc = lca_finder(root);
        return low_com_anc.first;
    }
};

int main() {
    return 0;
}