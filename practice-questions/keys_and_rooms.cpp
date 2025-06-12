#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> vis_rooms;
        queue<int> q;

        q.push(0);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int curr_room = q.front();
                q.pop();
                vis_rooms.insert(curr_room);

                vector<int> keys = rooms[curr_room];
                for (int j = 0; j < keys.size(); j++) {
                    if (vis_rooms.find(keys[j]) == vis_rooms.end()) {
                        q.push(keys[j]);
                    }
                }
            }
        }
        return vis_rooms.size() == rooms.size();
    }
};

int main() {
    return 0;
}