#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int max = n*n;
        queue<int> q;
        q.push(1);
        vector<bool> visited(max + 1, false);
        visited[1] = true;

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();

                if (curr == max) return level;

                for (int next = curr + 1; next <= min(curr+6, max); next++) {
                    int dest = next;

                    int row = (next - 1) / n;
                    int col = (next - 1) % n;
                    if (row%2 == 1) col = n-1-col;

                    row = n - 1 - row;

                    if (board[row][col] != -1) dest = board[row][col];
                    if (!visited[dest]) {
                        visited[dest]  = true;
                        q.push(dest);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

int main() {
    return 0;
}