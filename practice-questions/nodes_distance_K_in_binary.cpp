#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode*  right;
};

class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    void preorder_traverse(TreeNode* curr, TreeNode* par) {
        if (!curr) return;
        parent[curr] = par;
        preorder_traverse(curr->left, curr);
        preorder_traverse(curr->right, curr);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preorder_traverse(root, NULL);

        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;

        while(!q.empty() && k) {
            k-=1;
            int size = q.size();
            for (int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                visited.insert(curr);

                if (!visited.count(curr->left) && curr->left) q.push(curr->left);
                if (!visited.count(curr->right) && curr->right) q.push(curr->right);
                if (!visited.count(parent[curr]) && parent[curr]) q.push(parent[curr]);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};

int main() {
    return 0;
}