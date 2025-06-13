#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> another_grid = grid;
        int n_of_fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (another_grid[i][j] == 2) q.push({i,j});
                else if (another_grid[i][j] == 1) n_of_fresh++;
            }
        }

        int mins = -1;
        while (!q.empty()) {
            int size_of_lvl = q.size();
            for (int k = 0; k < size_of_lvl; k++) {
                auto [i,j] = q.front();
                q.pop();
                if (i + 1 < grid.size() && another_grid[i+1][j] == 1) {
                    another_grid[i+1][j] = 2;
                    n_of_fresh--;
                    q.push({i+1,j});
                }
                if (i - 1 >= 0 && another_grid[i-1][j] == 1) {
                    another_grid[i-1][j] = 2;
                    n_of_fresh--;
                    q.push({i-1,j});
                }
                if (j + 1 < grid[0].size() && another_grid[i][j+1] == 1) {
                    another_grid[i][j+1] = 2;
                    n_of_fresh--;
                    q.push({i,j+1});
                }
                if (j - 1 >= 0 && another_grid[i][j-1] == 1) {
                    another_grid[i][j-1] = 2;
                    n_of_fresh--;
                    q.push({i,j-1});
                }
            }
            mins++;
        }
        if (n_of_fresh > 0) return -1;
        if (mins == -1) return 0;
        return mins;
    }
};

int main() {
    return 0;
}