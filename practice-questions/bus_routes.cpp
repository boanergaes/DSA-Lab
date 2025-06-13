#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> bus_id_map;
        for (int i = 0; i < routes.size(); i++) {
            int bid = i;
            vector<int> bus_stops = routes[i];
            for (auto bus_stop : bus_stops) {
                bus_id_map[bus_stop].push_back(bid);
            }
        }

        queue<pair<int, int>> q;
        unordered_map<int, bool> bus_visited, bus_stop_visited;
        q.push({source, 0});
        bus_stop_visited[source] = true;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> p = q.front();
                q.pop();

                int curr_stop = p.first;
                int bus_travelled = p.second;

                if (curr_stop == target) return bus_travelled;

                for (auto bus : bus_id_map[curr_stop]) {
                    if (bus_visited[bus]) continue;
                    bus_visited[bus] = true;
                    for (auto bus_stop : routes[bus]) {
                        if (bus_stop_visited[bus_stop]) continue;
                        bus_stop_visited[bus_stop] = true;
                        q.push({bus_stop, bus_travelled + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}