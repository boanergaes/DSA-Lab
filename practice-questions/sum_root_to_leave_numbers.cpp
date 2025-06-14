#include <vector>
#include <string>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    void accumulator(TreeNode* root, string str, vector<string>& buff) {
        if (!root->left && !root->right) {
            str += to_string(root->val);
            buff.push_back(str);
            return;
        }
        str += to_string(root->val);
        if (root->left) accumulator(root->left, str, buff);
        if (root->right) accumulator(root->right, str, buff);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        vector<string> buff;
        accumulator(root, "", buff);
        for (auto i : buff) {
            sum += stoi(i);
        }
        return sum;
    }
};

int main() {
    return 0;
}