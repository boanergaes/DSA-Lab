#include <vector>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

class Solution {
    void dfs(string s, string d, unordered_map<string, vector<pair<string, double>>>& map, set<string>& vis, double& ans, double temp) {
        if (vis.find(s) != vis.end()) return;
        vis.insert(s);
        if (s==d){
            ans = temp;
            return;
        }
        for (auto a : map[s]) {
            dfs(a.first, d, map, vis, ans, temp*a.second);

        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mapping;
        for (int i = 0; i<equations.size(); i++) {
            mapping[equations[i][0]].push_back({equations[i][1], values[i]});
            mapping[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            string s = queries[i][0];
            string d = queries[i][1];
            set <string> visited;
            double ans = -1.0;
            if (mapping.find(s) != mapping.end())
                dfs(s,d,mapping,visited, ans,1.0);
            res.push_back(ans);
        }
        return res;
    }
};

int main() {
    return 0;
}