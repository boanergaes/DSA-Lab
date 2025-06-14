#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O')
            return;
        board[r][c] = '#';
        dfs(r + 1, c, board);
        dfs(r - 1, c, board);
        dfs(r, c + 1, board);
        dfs(r, c - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][cols - 1] == 'O') dfs(i, cols - 1, board);
        }

        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[rows - 1][j] == 'O') dfs(rows - 1, j, board);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

int main() {
    return 0;
}