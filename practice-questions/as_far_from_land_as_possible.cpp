#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    const vector<int> dx = {0,0,-1,1};
    const vector<int> dy = {-1,1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j<c; j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    grid[i][j] = 2;
                }
            }
        }
        if (q.size() == r*c || q.empty()) return -1;
        int maximum = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nxti = node.first + dx[i];
                    int nxtj = node.second + dy[i];
                    if ((nxti >= 0 && nxtj >=0) && (nxti < r && nxtj < c)) {
                        if (grid[nxti][nxtj] == 0) {
                            q.push({nxti, nxtj});
                            grid[nxti][nxtj] = 2;
                        }
                    }
                }
            }
            maximum++;
        }
        return maximum - 1;
    }
};

int main() {
    return 0;
}