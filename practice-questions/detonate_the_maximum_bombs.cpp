#include <vector>
#include <cmath>
using namespace std;

class Solution {
    int detonate(vector<vector<int>>& bombs, vector<bool>& detonated, int i) {
        int res = 0;
        int n = bombs.size();
        for (int j = 0; j < n; j++) {
            if (!detonated[j]) {
                int x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
                int p = bombs[j][0], q = bombs[j][1], d = bombs[j][2];
                long distance_sqr = pow(x-p, 2) + pow(q-y, 2);
                if (distance_sqr <= (long)r*r) {
                    detonated[j] = true;
                    res += 1 + detonate(bombs, detonated, j);
                }
            }
        }
        return res;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int max_detonated = 0;
        int n = bombs.size();

        for (int i = 0; i < n; i++) {
            vector<bool> detonated(n, false);
            detonated[i] = true;
            int curr = 1 + detonate(bombs, detonated, i);
            if (max_detonated < curr) max_detonated = curr;
            // max_detonated = max(max_detonated, curr);
        }
        return max_detonated;
    }
};

int main() {
    return 0;
}