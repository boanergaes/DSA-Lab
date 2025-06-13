#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
   const int INF = 1e9;
   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int rows = mat.size();
      int colms = mat[0].size();
      vector<pair<int, int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
      deque<pair<int, int>> q;
      for (int  r= 0; r < rows; r++) {
         for (int c = 0; c < colms; c++) {
            if (mat[r][c] == 0) q.push_back({r,c});
            else mat[r][c] = INF;
         }
      }
      while (!q.empty()) {
         pair<int, int> l = q.front();
         int row = l.first;
         int colm = l.second;
         q.pop_front();

         for (auto d : dir) {
            int nw_row = row + d.first;
            int nw_colm = colm + d.second;

            if ((0 <= nw_row && nw_row < rows) && (0 <= nw_colm && nw_colm < colms) && (mat[nw_row][nw_colm] > mat[row][colm] + 1)) {
               mat[nw_row][nw_colm] =  mat[row][colm] + 1;
               q.push_back({nw_row, nw_colm});
            }
         }
      }
      return mat;
   }
};


int main() {
   return 0;
}