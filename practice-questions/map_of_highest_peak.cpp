#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            int x = a.first, y = a.second;
            int v = ans[x][y];
            vector<int> temp = {-1, 0, 1, 0, -1};
            for (int k = 0; k < temp.size() - 1; k++) {
                if (x + temp[k] >= 0 && x + temp[k] < n && y + temp[k+1] < m && y + temp[k+1] >= 0) {
                    if (ans[x+temp[k]][y+temp[k+1]] == -1) {
                        ans[x+temp[k]][y+temp[k+1]] = v+1;
                        q.push({x+temp[k], y+temp[k+1]});
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}