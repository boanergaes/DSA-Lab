#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> ddends(deadends.begin(), deadends.end());
        unordered_set<string> visited;

        queue<string> q;
        string init = "0000";
        if (ddends.find(init) != ddends.end()) return -1;

        q.push(init);
        visited.insert(init);

        int res = 0;
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0; i < count; i++) {
                string t = q.front();
                q.pop();

                if (t == target) return res;

                vector<string> neighbor_nodes = neighbor_node_getter(t);

                for (auto node : neighbor_nodes) {
                    if (ddends.find(node) == ddends.end() && visited.find(node) == visited.end()) {
                        q.push(node);
                        visited.insert(node);
                    }
                }
            }
            res++;
        }
        return -1;
    }

    vector<string> neighbor_node_getter(string key) {
        vector<string> res;
        for (int i = 0; i < 4; i++) {
            string temp = key;
            temp[i] = (key[i] - '0' + 1)%10 + '0';
            res.push_back(temp);

            temp[i] = (key[i] - '0' - 1 + 10)%10 + '0';
            res.push_back(temp);

        }
        return res;
    }
};

int main() {
    return 0;
}