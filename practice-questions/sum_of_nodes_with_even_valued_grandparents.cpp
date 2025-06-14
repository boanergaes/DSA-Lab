struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool hasGrandC(TreeNode* root) const {
        bool ll = false, lr = false, rl = false, rr = false;
        if (!root) return false;
        if (root->left) {
            if (root->left->left) ll = true;
            if (root->left->right) lr = true;
        }
        if (root->right) {
            if (root->right->left) rl = true;
            if (root->right->right) rr = true;
        }

        return ll || lr || rl || rr;
    }

    void accumulator(TreeNode* root, int& sum) {
        if (!hasGrandC(root)) return;
        if (root->val % 2 == 0) {
            if (root->left) {
                if (root->left->left) sum += root->left->left->val;
                if (root->left->right) sum += root->left->right->val;
            }
            if (root->right) {
                if (root->right->left) sum += root->right->left->val;
                if (root->right->right) sum += root->right->right->val;
            }
        }
        accumulator(root->left, sum);
        accumulator(root->right, sum);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        accumulator(root, sum);
        return sum;
    }
};

int main() {
    return 0;
}