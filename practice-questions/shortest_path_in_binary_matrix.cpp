#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int, int>> posbl_dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,-1}, {-1,1}};

        int n = grid.size();

        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        queue<pair<int, int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        while(!q.empty()) {
            pair<int, int> curr_cords = q.front();
            q.pop();

            int row = curr_cords.first;
            int col = curr_cords.second;

            int d = grid[row][col];

            if (row == n-1 && col == n-1) {
                return d;
            }

            for (auto& dir : posbl_dirs) {
                int dr = dir.first;
                int dc = dir.second;

                int nr = row + dr;
                int nc = col + dc;

                if ((nr < n && nr >= 0) && (nc < n && nc >= 0) && (grid[nr][nc] == 0)) {
                    q.push(make_pair(nr, nc));
                    grid[nr][nc] = d + 1;
                }
            }
        }
        return -1;
    }
};

int main() {

return 0;
}