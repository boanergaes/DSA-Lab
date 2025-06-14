#include <unordered_map>
#include <vector>
using namespace std;

struct Employee {
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
    int accumulate(unordered_map<int, Employee*>& map, const int id){
        auto sum = map[id]->importance;
        for(const auto element : map[id]->subordinates){
            sum += accumulate(map, element);
        }
        return sum;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;
        for(auto element : employees){
            map[element->id] = element;
        }
        return accumulate(map, id);
    }
};

int main() {
    return 0;
}